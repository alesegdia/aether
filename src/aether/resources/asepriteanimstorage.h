#pragma once

#include "aether/resources/baseassetstorage.h"
#include "aether/render/asepriteanimloader.h"


/*

namespace aether
{
	namespace resources
	{

		class AsepriteAnimStorage : public BaseAssetStorage<aether::render::AsepriteAnimationData>
		{
		public:
			std::shared_ptr<aether::render::AsepriteAnimationData> LoadImpl(std::string path) override
			{
				std::string error;
				std::ifstream t(path);
				std::stringstream buffer;
				buffer << t.rdbuf();
				auto result = json11::Json::parse(buffer.str(), error);


				if(result["meta"]["app"] == "https://www.aseprite.org/")
				{
					render::AsepriteAnimationLoader loader;
					auto data = loader.Load(path);
					return std::make_shared<render::AsepriteAnimationData>(data);
				}
				SetLoadMessage(path + " is not an aseprite file.");
				return nullptr;
			}
		};

	}
}

*/