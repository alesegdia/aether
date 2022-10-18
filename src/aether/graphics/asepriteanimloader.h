#pragma once

#include "animation.h"
#include "../json11.hpp"

#include <fstream>
#include <sstream>
#include <unordered_map>

namespace aether
{

    namespace graphics{


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

    LoadedAnimationData Load(const std::string& path);
};

        
}
}