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

	aether::render::Camera* GLRenderModule::CreateCamera(const math::Vec2f& viewport)
	{
		m_allCameras.emplace_back(viewport);
		return &m_allCameras.back();
	}

	aether::render::Camera* GLRenderModule::CreateCamera(const math::Vec2f& viewport)
	{
		m_allCameras.emplace_back(viewport);
		return &m_allCameras.back();
	}

	aether::render::Sprite* GLRenderModule::CreateSprite(Texture* texture, const math::Recti& rect)
	{
		m_allSprites.emplace_back(texture, rect);
		return &m_allSprites.back();
	}

	aether::render::ShaderProgram* GLRenderModule::LoadShaderFromFile(const std::string& vspath, const std::string& fspath)
	{

	}

	GLRenderModule::GLRenderModule() : IRenderModule(nullptr)
	{

	}

	IRenderModule* create_render_module()
	{
		return new GLRenderModule();
	}

	void GLBatchDispatcher::BindTextures(Batch& batch)
	{
		auto gltex = ResourceCast(batch.GetTexture());
		batch.GetTexture()->Bind(nether::TextureUnit::Texture0);
	}

}