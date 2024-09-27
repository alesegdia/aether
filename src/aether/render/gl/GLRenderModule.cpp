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

	IRenderModule* create_render_module()
	{
		return new GLRenderModule();
	}

}