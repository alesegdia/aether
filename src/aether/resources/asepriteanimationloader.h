#pragma once

#include "../json11.hpp"

class AsepriteAnimationLoader
{
public:
    AsepriteAnimationLoader(const char* filepath)
    {
        std::string error;
        auto data = json11::Json::parse(filepath, error);
    }

private:


};
