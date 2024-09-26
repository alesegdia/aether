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
			SheetAssetStorage(render::IRenderModule* renderModule)
				: m_renderModule(renderModule)
			{

			}
			
			std::shared_ptr<aether::render::Spritesheet> LoadImpl(std::string path) override;

		private:
			std::vector<aether::render::Texture*> m_cachedTextures;
			render::IRenderModule* m_renderModule = nullptr;

		};

	}
}