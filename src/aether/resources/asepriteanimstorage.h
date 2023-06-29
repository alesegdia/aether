#pragma once

#include "aether/resources/baseassetstorage.h"
#include "aether/graphics/asepriteanimloader.h"


namespace aether
{
	namespace resources
	{

		class AsepriteAnimStorage : public BaseAssetStorage<aether::graphics::AsepriteAnimationData>
		{
		public:
			std::shared_ptr<aether::graphics::AsepriteAnimationData> LoadImpl(std::string path) override
			{
				std::string error;
				std::ifstream t(path);
				std::stringstream buffer;
				buffer << t.rdbuf();
				auto result = json11::Json::parse(buffer.str(), error);


				if(result["meta"]["app"] == "https://www.aseprite.org/")
				{
					graphics::AsepriteAnimationLoader loader;
					auto data = loader.Load(path);
					return std::make_shared<graphics::AsepriteAnimationData>(data);
				}
				SetLoadMessage(path + " is not an aseprite file.");
				return nullptr;
			}
		};

	}
}