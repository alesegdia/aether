#pragma once

#include "aether/graphics/texture.h"
#include "aether/resources/baseassetstorage.h"

namespace aether
{
	namespace resources
	{
		
		class TextureAssetStorage : public BaseAssetStorage<aether::graphics::Texture>
		{
		public:
			std::shared_ptr<aether::graphics::Texture> LoadImpl(std::string path) override;

		};

	}
}