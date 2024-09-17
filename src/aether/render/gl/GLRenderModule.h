#pragma once

#include "aether/core/ModuleObject.h"
#include "aether/core/handledresourcemanager.h"
#include "aether/render/IRenderModule.h"

#include <nether/nether.h>

namespace aether::render {

	class GLRenderModule : public IRenderModule
	{
	public:
		
		std::shared_ptr<Texture> LoadTextureFromFile(const std::string& path) override
		{
			std::shared_ptr<nether::Texture> netherTex = std::make_shared<nether::Texture>();
			std::shared_ptr<aether::render::GLTexture> tex = std::make_shared<aether::render::GLTexture>(this, netherTex);
			netherTex->LoadFromFile(path, nether::TextureFormat::RGBA8);
			return tex;
		}

	};

}