#pragma once

#include "aether/render/gl/GLSceneNode.h"
#include "aether/render/gl/GLTexture.h"
#include "aether/render/gl/GLFont.h"
#include "aether/render/IRenderModule.h"

#include <nether/nether.h>

namespace aether::render {

	class GLSceneNode;

	class GLBatch
	{
	public:
		GLBatch(nether::Texture* texture, nether::ShaderProgram* shader)
			: m_texture(texture)
			, m_shader(shader)
		{

		}

		nether::Texture* GetTexture() const
		{
			return m_texture;
		}

		nether::ShaderProgram* GetShader() const
		{
			return m_shader;
		}

		void RemoveElement(const GLSceneNode* node)
		{
			m_elements.erase(std::remove(m_elements.begin(), m_elements.end(), node), m_elements.end());
		}

		void AddElement(const GLSceneNode* node)
		{
			m_elements.push_back(node);
		}

		const std::vector<const GLSceneNode*>& GetElements() const
		{
			return m_elements;
		}

	private:
		nether::Texture* m_texture;
		nether::ShaderProgram* m_shader;
		std::vector<const GLSceneNode*> m_elements;

	};

	class GLRenderModule : public IRenderModule
	{
	public:
		GLRenderModule()
			: IRenderModule(nullptr)
		{

		}

		virtual ~GLRenderModule();

		Texture* LoadTextureFromFile(const std::string& path) override;
		Font* LoadFontFromFile(const std::string& path) override;

		math::Vec2i GetTextureSize(const Texture* tex);


		void AddToBatch(const GLSceneNode* node);

		void RemoveFromBatch(const GLSceneNode* node);

		GLBatch* GetBestBatchForNode(const GLSceneNode* node);

		void Render();

		Camera* CreateCamera(const math::Vec2f& viewport) override
		{
			return nullptr;
		}

	private:

		GLBatch* AddBatchForNode(const GLSceneNode* node);

		static constexpr int SameShaderScore = 1;
		static constexpr int SameTextureScore = 1;

		std::vector<GLBatch> m_batches;
		std::vector<Texture> m_allTextures;
		std::vector<Font> m_allFonts;

	};

}