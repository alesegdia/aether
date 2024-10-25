
#include <algorithm>
#include <unordered_map>
#include "aether/render/BatchDispatcher.h"
#include "aether/render/IBatchedEntity.h"
#include "aether/render/Shaderprogram.h"
#include "aether/render/Texture.h"

namespace aether::render
{

	BatchDispatcher::BatchDispatcher(IBatchActionProvider* batchAction)
		: m_batchActionProvider(batchAction)
	{

	}


	void BatchDispatcher::AddToBatch(IBatchedEntity* node)
	{
		auto batch = GetBestBatchForNode(node);
		batch->AddElement(node);
	}

	Batch* BatchDispatcher::AddBatchForNode(IBatchedEntity* node)
	{
		// add batch with node properties
		Batch* batch = new Batch(node->GetTextureConfig(), node->GetShader());
		m_batches.push_back(batch);

		// sort first by texture and then by shader
		std::sort(m_batches.begin(), m_batches.end(), [](const Batch* b1, const Batch* b2) {
			return b1->GetOrder() > b2->GetOrder();
		});
		std::sort(m_batches.begin(), m_batches.end(), [](const Batch* b1, const Batch* b2) {
			return b1->GetOrder() > b2->GetOrder();
		});

		return batch;
	}

	void BatchDispatcher::Render()
	{
		render::ShaderProgram* prevShader = nullptr;
		render::TextureConfig prevTexture;
		
		// m_perfData.numElementsPerBatch.clear();
		for (auto& batch : m_batches)
		{
			// m_perfData.numElementsPerBatch.push_back(batch->GetElements().size());
			auto currentShader = batch->GetShader();
			if (currentShader != prevShader)
			{
				prevShader = currentShader;
				m_batchActionProvider->ShaderPreparationStep(*batch);
				m_batchActionProvider->TexturePreparationStep(*batch);
				prevTexture = batch->GetTextureConfig();
			}

			auto currentTexture = batch->GetTextureConfig();
			if (currentTexture != prevTexture)
			{
				m_batchActionProvider->TexturePreparationStep(*batch);
				prevTexture = currentTexture;
			}
			
			m_batchActionProvider->StartRenderElementsStep();
			std::unordered_map<InstancedEntity*, InstanceBatch> instanceBatches;
			for (auto& element : batch->GetElements())
			{
				auto instancedEntity = element->GetInstancedEntity();
				if (instancedEntity != nullptr)
				{
					auto instancedEntity = element->GetInstancedEntity();
					assert(instancedEntity != nullptr);

					if (!instanceBatches.contains(instancedEntity))
					{
						instanceBatches[instancedEntity] = InstanceBatch();
					}
					instanceBatches[instancedEntity].elements.push_back(const_cast<IBatchedEntity*>(element));
				}
				else
				{
					m_batchActionProvider->RenderElement(*element, *batch);
				}
			}
			m_batchActionProvider->FinishRenderElementsStep();

			for (auto& [instancedEntity, instanceBatch] : instanceBatches)
			{
				m_batchActionProvider->RenderInstanced(instancedEntity, &instanceBatch);
			}
		}
	}

	aether::render::Batch* BatchDispatcher::GetBestBatchForNode(IBatchedEntity* node)
	{
		Batch* selectedBatch = nullptr;
		int bestBatchScore = 0;

		for (auto& batch : m_batches)
		{
			int currentBatchScore = 0;
			if (batch->GetTextureConfig() == node->GetTextureConfig())
			{
				currentBatchScore += SameTextureScore;
			}
			if (batch->GetShader() == node->GetShader())
			{
				currentBatchScore += SameShaderScore;
			}
			if (currentBatchScore >= bestBatchScore)
			{
				bestBatchScore = currentBatchScore;
				selectedBatch = batch;
			}
		}

		if (selectedBatch == nullptr)
		{
			selectedBatch = AddBatchForNode(node);
		}

		return selectedBatch;
	}

	void BatchDispatcher::RemoveFromBatch(IBatchedEntity* node)
	{
		static std::vector<int> points = {};
		while (points.size() < m_batches.size())
		{
			points.push_back(0);
		}

		Batch* bestBatch = nullptr;
		int bestBatchScore = 0;


		for (auto& batch : m_batches)
		{
			batch->RemoveElement(node);
		}
	}

}