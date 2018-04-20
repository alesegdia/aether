#pragma once

#include "../core/handle.h"

namespace aether {
namespace graphics {


class Texture : public core::Handle
{
public:

    Texture()
    {

    }

    int height();
    int width();
    void destroy();
    void draw(float x, float y);
    void load(const char* path);

};


}
}
