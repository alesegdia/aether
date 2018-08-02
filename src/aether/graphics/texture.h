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
    void draw(float x, float y, float alpha);
    void load(const char* path);
    Texture subdivide(int x, int y, int w, int h);

private:

    Texture(int h)
    {
        handle(h);
    }


};

}
}
