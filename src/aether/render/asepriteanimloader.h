#pragma once

#include "animation.h"
#include "../json11.hpp"

#include <fstream>
#include <sstream>
#include <unordered_map>

namespace aether::render {


using AnimationsMap = std::unordered_map<std::string, std::shared_ptr<aether::graphics::Animation>>;

        struct FrameData
        {
	        TextureRegion region;
            int duration;
        };

struct AsepriteAnimationData
{
    AnimationsMap anims;
    aether::graphics::Texture texture;
};

class AsepriteAnimationLoader
{
public:

    AsepriteAnimationData Load(const std::string& path);
};

        
}
