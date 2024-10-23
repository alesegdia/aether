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
			SheetAssetStorage()
			{

			}
			
			aether::render::Spritesheet* LoadImpl(std::string path) override;

		private:
			std::vector<aether::render::Texture*> m_cachedTextures;
			std::vector<aether::render::Spritesheet*> m_cachedSheets;

		};

	}
}