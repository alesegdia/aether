#pragma once

#include "aether/core/ModuleObject.h"
#include "aether/render/Texture.h"
#include "aether/render/Font.h"
#include "aether/render/ShaderProgram.h"
#include "aether/render/Camera.h"

namespace aether::render
{

    class IRenderModule : public core::ModuleObject
    {
    protected:
        IRenderModule(ModuleObject* o) : ModuleObject(o) {}

    public:
        virtual Texture* LoadTextureFromFile(const std::string& path) = 0;
		virtual Font* LoadFontFromFile(const std::string& path) = 0;
		virtual ShaderProgram* LoadShaderFromFile(const std::string& vspath, const std::string& fspath) = 0;
		virtual Camera* CreateCamera(const math::Vec2f& viewport) = 0;

		virtual ISprite3D CreateSprite(Texture* texture, const math::Recti& rect);

        virtual math::Vec2i GetTextureSize(const Texture* tex) = 0;

    };

	class IBatchedEntity
	{
	public:
		virtual ShaderProgram* GetShader();
		virtual Texture* GetTexture();
		virtual Topology* GetTopology();
	};

	class Batch
	{
	public:
		Batch(Texture* texture, render::ShaderProgram* shader)
			: m_texture(texture)
			, m_shader(shader)
		{

		}

		render::Texture* GetTexture() const
		{
			return m_texture;
		}

		render::ShaderProgram* GetShader() const
		{
			return m_shader;
		}

		void RemoveElement(const IBatchedEntity* node)
		{
			m_elements.erase(std::remove(m_elements.begin(), m_elements.end(), node), m_elements.end());
		}

		void AddElement(const IBatchedEntity* node)
		{
			m_elements.push_back(node);
		}

	private:
		render::Texture* m_texture;
		render::ShaderProgram* m_shader;
		std::vector<const IBatchedEntity*> m_elements;

	};

	class RenderModule : public IRenderModule
	{
	public:
		RenderModule()
			: IRenderModule(this)
		{

		}

		virtual ~RenderModule();

		void AddToBatch(const IBatchedEntity* node)
		{
			auto batch = GetBestBatchForNode(node);
			batch->AddElement(node);
		}

		void RemoveFromBatch(const IBatchedEntity* node)
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

		Batch* GetBestBatchForNode(const IBatchedEntity* node)
		{
			GLBatch* selectedBatch = nullptr;
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

		virtual void BindTextures(Batch& batch) = 0;

		void Render()
		{
			render::ShaderProgram* prevShader = nullptr;
			render::Texture* prevTexture;

			for (auto& batch : m_batches)
			{
				auto currentShader = batch.GetShader();
				if (currentShader != prevShader)
				{
					prevShader = currentShader;
					currentShader->Use();
					BindTextures(batch);
					batch.GetTexture()->Bind(render::TextureUnit::Texture0);
					prevTexture = batch.GetTexture();
				}
				else
				{
					auto currentTexture = batch.GetTexture();
					if (currentTexture != prevTexture)
					{
						currentTexture->Bind(nether::TextureUnit::Texture0);
						prevTexture = currentTexture;
					}
				}

				for (auto& element : batch.GetElements())
				{
					// element->Render();
				}
			}
		}

		Camera* CreateCamera(const math::Vec2f& viewport) override
		{
			return nullptr;
		}

	private:

		Batch* AddBatchForNode(const IBatchedEntity* node)
		{
			// add batch with node properties
			Batch batch(node->(), node->GetShader());
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

		static constexpr int SameShaderScore = 1;
		static constexpr int SameTextureScore = 1;

		std::vector<Batch> m_batches;

	};



}

