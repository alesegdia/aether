#include "asepriteanimloader.h"

namespace aether::graphics {

	LoadedAnimationData AsepriteAnimationLoader::Load(const std::string& path)
	{
		LoadedAnimationData data;

		std::string error;
		std::ifstream t(path);
		std::stringstream buffer;
		buffer << t.rdbuf();
		auto result = json11::Json::parse(buffer.str(), error);
		auto frames = result["frames"].array_items();
		auto meta = result["meta"];
		data.texture.Load(meta["image"].string_value().c_str());
		data.sheet = std::make_shared<aether::graphics::Spritesheet>();

		for(auto frame : frames)
		{
			
		}

		auto firstFrame = frames[0];
		auto frameWidth = firstFrame["frame"]["w"].int_value();
		auto frameHeight = firstFrame["frame"]["h"].int_value();

		auto imgWidth = meta["size"]["w"].int_value();
		auto imgHeight = meta["size"]["h"].int_value();

		int numColumns = imgWidth / frameWidth;
		int numRows = imgHeight / frameHeight;


		for (auto anim : meta["frameTags"].array_items())
		{
			auto name = anim["name"].string_value();
			assert(data.anims.count(name) == 0);

			auto frameStart = anim["from"].int_value();
			auto frameEnd = anim["to"].int_value();

			auto animobj = std::make_shared<aether::graphics::Animation>();

			while (frameStart <= frameEnd)
			{
				auto duration = frames[frameStart]["duration"].int_value();
				animobj->AddFrame(*data.sheet->GetFrame(frameStart), duration);
				frameStart++;
			}

			data.anims[name] = animobj;
		}

		return data;
	}

}

