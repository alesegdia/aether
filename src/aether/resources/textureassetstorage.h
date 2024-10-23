#pragma once

#include "aether/render/texture.h"
#include "aether/resources/baseassetstorage.h"

namespace aether
{
	namespace resources
	{
		
		class TextureAssetStorage : public BaseAssetStorage<aether::render::Texture>
		{
		public:
			aether::render::Texture* LoadImpl(std::string path) override;

		};

	}
}