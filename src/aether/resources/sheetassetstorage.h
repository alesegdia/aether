#pragma once

#include "aether/graphics/spritesheet.h"
#include "aether/resources/baseassetstorage.h"

namespace aether
{
	namespace resources
	{

		class SheetAssetStorage : public BaseAssetStorage<aether::graphics::Spritesheet>
		{
		public:
			std::shared_ptr<aether::graphics::Spritesheet> LoadImpl(std::string path) override;

		private:
			std::vector<std::shared_ptr<aether::graphics::Texture>> m_cachedTextures;

		};

	}
}