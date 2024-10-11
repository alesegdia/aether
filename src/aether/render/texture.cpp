#pragma once

#include "aether/render/texture.h"
#include "aether/render/IRenderModule.h"

namespace aether::render
{

	TextureConfig CreateSingleTextureConfig(Texture* texture, int slot)
	{
		TextureConfig config;
		config.AddEntrySorted(slot, texture);
		return config;
	}


	IRenderModule* Texture::GetRenderer() const { return (IRenderModule*)owner; }

}

