#include "aether/render/gl/GLRenderModule.h"
#include "aether/render/gl/GLSceneNode.h"

namespace aether::render {

	inline GLRenderModule::~GLRenderModule()
	{
		m_allFonts.clear();
		m_allTextures.clear();
	}
	
	inline Texture* GLRenderModule::LoadTextureFromFile(const std::string& path)
	{
		std::shared_ptr<nether::Texture> netherTex = std::make_shared<nether::Texture>();
		m_allTextures.emplace_back(this, netherTex);
		netherTex->LoadFromFile(path, nether::TextureFormat::RGBA8);
		return &m_allTextures.back();
	}
	inline Font* GLRenderModule::LoadFontFromFile(const std::string& path)
	{
		/*
		FT_Face face;
		if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face))
		{
			std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
			return -1;
		}
		*/
	}

	inline void GLRenderModule::AddToBatch(const GLSceneNode* node)
	{
		auto batch = GetBestBatchForNode(node);
		batch->AddElement(node);
	}
	inline void GLRenderModule::RemoveFromBatch(const GLSceneNode* node)
	{
		static std::vector<int> points = {};
		while (points.size() < m_batches.size())
		{
			points.push_back(0);
		}

		GLBatch* bestBatch = nullptr;
		int bestBatchScore = 0;


		for (auto& batch : m_batches)
		{
			batch.RemoveElement(node);
		}
	}
	inline GLBatch* aether::render::GLRenderModule::GetBestBatchForNode(const GLSceneNode* node)
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

inline void GLRenderModule::Render()
{
	nether::ShaderProgram* prevShader = nullptr;
	nether::Texture* prevTexture;

	for (auto& batch : m_batches)
	{
		auto currentShader = batch.GetShader();
		if (currentShader != prevShader)
		{
			prevShader = currentShader;
			currentShader->Use();
			batch.GetTexture()->Bind(nether::TextureUnit::Texture0);
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

inline GLBatch* GLRenderModule::AddBatchForNode(const GLSceneNode* node)
{
	// add batch with node properties
	GLBatch batch(node->GetTexture(), node->GetShader());
	m_batches.push_back(batch);

	// sort first by texture and then by shader
	std::sort(m_batches.begin(), m_batches.end(), [](const GLBatch& b1, const GLBatch& b2) {
		return b1.GetTexture() > b2.GetTexture();
		});
	std::sort(m_batches.begin(), m_batches.end(), [](const GLBatch& b1, const GLBatch& b2) {
		return b1.GetShader() > b2.GetShader();
		});

	// return last element
	return &(m_batches.back());
}

IRenderModule* create_render_module()
{
	return new GLRenderModule();
}

}