#pragma once

#include "aether/render/spritesheet.h"
#include "aether/resources/baseassetstorage.h"

namespace aether
{
	namespace resources
	{

		class SheetAssetStorage : public BaseAssetStorage<aether::render::Spritesheet>
		{
		public:
			std::shared_ptr<aether::render::Spritesheet> LoadImpl(std::string path) override;

		private:
			std::vector<std::shared_ptr<aether::render::Texture>> m_cachedTextures;

		};

	}
}