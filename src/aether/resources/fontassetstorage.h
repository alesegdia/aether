#pragma once

#include "aether/resources/baseassetstorage.h"
#include "aether/graphics/font.h"


namespace aether
{
	namespace resources
	{

		class FontAssetStorage : public BaseAssetStorage<aether::graphics::Font>
		{
		public:
			std::shared_ptr<aether::graphics::Font> LoadImpl(std::string path) override;
		};

	}
}