
#include <algorithm>

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


	inline void BatchDispatcher::AddToBatch(const IBatchedEntity* node)
	{
		auto batch = GetBestBatchForNode(node);
		batch->AddElement(node);
	}

	aether::render::Batch* BatchDispatcher::AddBatchForNode(const IBatchedEntity* node)
	{
		// add batch with node properties
		Batch batch(node->GetTexture(), node->GetShader());
		m_batches.push_back(batch);

		// sort first by texture and then by shader
		std::sort(m_batches.begin(), m_batches.end(), [](const Batch& b1, const Batch& b2) {
			return b1.GetTexture() > b2.GetTexture();
			});
		std::sort(m_batches.begin(), m_batches.end(), [](const Batch& b1, const Batch& b2) {
			return b1.GetShader() > b2.GetShader();
			});

		// return last element
		return &(m_batches.back());
	}

	void BatchDispatcher::Render()
	{
		render::ShaderProgram* prevShader = nullptr;
		render::Texture* prevTexture = nullptr;

		for (auto& batch : m_batches)
		{
			auto currentShader = batch.GetShader();
			if (currentShader != prevShader)
			{
				prevShader = currentShader;
				m_batchActionProvider->ShaderPreparationStep(batch);
				m_batchActionProvider->TexturePreparationStep(batch);
				prevTexture = batch.GetTexture();
			}
			else
			{
				auto currentTexture = batch.GetTexture();
				if (currentTexture != prevTexture)
				{
					m_batchActionProvider->TexturePreparationStep(batch);
					prevTexture = currentTexture;
				}
			}

			m_batchActionProvider->StartRenderElementsStep();
			for (auto& element : batch.GetElements())
			{
				m_batchActionProvider->RenderElement(*element, batch);
			}
			m_batchActionProvider->FinishRenderElementsStep();
		}
	}

	aether::render::Batch* BatchDispatcher::GetBestBatchForNode(const IBatchedEntity* node)
	{
		Batch* selectedBatch = nullptr;
		int bestBatchScore = 0;

		for (auto& batch : m_batches)
		{
			int currentBatchScore = 0;
			if (batch.GetTexture() == node->GetTexture())
			{
				currentBatchScore += SameTextureScore;
			}
			if (batch.GetShader() == node->GetShader())
			{
				currentBatchScore += SameShaderScore;
			}
			if (currentBatchScore >= bestBatchScore)
			{
				bestBatchScore = currentBatchScore;
				selectedBatch = &batch;
			}
		}

		if (selectedBatch == nullptr)
		{
			selectedBatch = AddBatchForNode(node);
		}

		return selectedBatch;
	}

	void BatchDispatcher::RemoveFromBatch(const IBatchedEntity* node)
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
			batch.RemoveElement(node);
		}
	}

}