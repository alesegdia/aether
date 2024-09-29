#pragma once

#include "aether/render/IRenderModule.h"
#include "aether/render/BatchDispatcher.h"

#include "aether/render/gl/GLCamera.h"
#include "aether/render/gl/GLFont.h"
#include "aether/render/gl/GLTexture.h"
#include "aether/scene/spritenode.h"


#include <nether/nether.h>

namespace aether::render {


	class GLBatchDispatcher : public BatchDispatcher
	{
	public:

	private:
		void BindTextures(Batch& batch) override;

	};

	class GLRenderModule : public IRenderModule
	{
	public:
		GLRenderModule();

		virtual ~GLRenderModule();

		// IRenderModule interface implementation
		Texture* LoadTextureFromFile(const std::string& path) override;
		Font* LoadFontFromFile(const std::string& path) override;

		ShaderProgram* LoadShaderFromFile(const std::string& vspath, const std::string& fspath) override;

		Camera* CreateCamera(const math::Vec2f& viewport) override;

		Sprite* CreateSprite(Texture* texture, const math::Recti& rect) override;

		void Render();

		Camera* CreateCamera(const math::Vec2f& viewport) override;

	private:

		GLBatchDispatcher m_batchDispatcher;
		std::vector<GLTexture> m_allTextures;
		std::vector<GLFont> m_allFonts;
		std::vector<Sprite> m_allSprites;
		std::vector<GLCamera> m_allCameras;

	};

}