#pragma once

#include "animation.h"
#include "../json11.hpp"

#include <fstream>
#include <sstream>
#include <unordered_map>

namespace aether {    
namespace graphics {


using AnimationsMap = std::unordered_map<std::string, std::shared_ptr<aether::graphics::Animation>>;

struct LoadedAnimationData
{
    AnimationsMap anims;
    std::shared_ptr<aether::graphics::Spritesheet> sheet;
    aether::graphics::Texture texture;
};

class AsepriteAnimationLoader
{
public:

    LoadedAnimationData load(const std::string& path)
    {
        LoadedAnimationData data;

        std::string error;
        std::ifstream t(path);
        std::stringstream buffer;
        buffer << t.rdbuf();
        auto result = json11::Json::parse(buffer.str(), error);
        auto frames = result["frames"].array_items();

        auto firstFrame = frames[0];
        auto frameWidth = firstFrame["frame"]["w"].int_value();
        auto frameHeight = firstFrame["frame"]["h"].int_value();

        auto meta = result["meta"];
        auto imgWidth = meta["size"]["w"].int_value();
        auto imgHeight = meta["size"]["h"].int_value();

        int numColumns = imgWidth / frameWidth;
        int numRows = imgHeight / frameHeight;

        data.texture.load(meta["image"].string_value().c_str());
        data.sheet = std::make_shared<aether::graphics::Spritesheet>(numColumns, numRows, data.texture);

        for( auto anim : meta["frameTags"].array_items() )
        {
            auto name = anim["name"].string_value();
            assert(data.anims.count(name) == 0);

            auto frameStart = anim["from"].int_value();
            auto frameEnd = anim["to"].int_value();

            auto animobj = std::make_shared<aether::graphics::Animation>();

            while( frameStart <= frameEnd )
            {
                auto duration = frames[frameStart]["duration"].int_value();
                animobj->addFrame(data.sheet->getFrame(frameStart), duration);
                frameStart++;
            }

            data.anims[name] = animobj;
        }

        return data;
    }
};

        
}
}
