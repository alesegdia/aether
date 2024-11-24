#pragma once

#include "aether/resources/baseassetstorage.h"
#include "aether/render/font.h"


namespace aether
{
	namespace resources
	{

		class FontAssetStorage : public BaseAssetStorage<aether::render::Font>
		{
		public:
			aether::render::Font* LoadImpl(std::string path) override;
		};

	}
}

