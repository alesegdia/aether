#include "asepriteanimloader.h"

#include <filesystem>

namespace aether::graphics {

	AsepriteAnimationData AsepriteAnimationLoader::Load(const std::string& path)
	{
		AsepriteAnimationData data;

		std::string error;
		std::ifstream t(path);
		std::stringstream buffer;
		buffer << t.rdbuf();
		auto result = json11::Json::parse(buffer.str(), error);
		auto frames = result["frames"].array_items();
		auto meta = result["meta"];
		auto image = meta["image"];
		auto basePath = std::filesystem::path(path).parent_path().generic_string();
		auto fullPath = basePath + "/" + std::string(meta["image"].string_value().c_str());
		data.texture.Load(fullPath.c_str());
		auto frameDatas = std::vector<FrameData>();

		for(auto frame : frames)
		{
			FrameData fd;
			auto x = frame["frame"]["x"].int_value();
			auto y = frame["frame"]["y"].int_value();
			auto w = frame["frame"]["w"].int_value();
			auto h = frame["frame"]["h"].int_value();
			auto frame_name = frame["filename"].string_value();
			fd.region = TextureRegion(data.texture, x, y, w, h);
			fd.duration = frame["duration"].int_value();
			frameDatas.push_back(fd);
		}

		for (auto anim : meta["frameTags"].array_items())
		{
			auto name = anim["name"].string_value();
			assert(data.anims.count(name) == 0);

			auto frameStart = anim["from"].int_value();
			auto frameEnd = anim["to"].int_value();

			auto animobj = std::make_shared<aether::graphics::Animation>();

			for(auto currentFrame = frameStart; currentFrame <= frameEnd; currentFrame++)
			{
				auto currentFrameData = frameDatas[currentFrame];
				auto duration = frameDatas[currentFrame].duration;
				auto region = currentFrameData.region;
				animobj->AddFrame(region, duration);
			}

			data.anims[name] = animobj;
		}

		return data;
	}

}

