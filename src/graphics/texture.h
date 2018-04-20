#pragma once

namespace aether {
namespace graphics {


class Texture
{
private:

    Texture(int handle);

    int m_handle = -1;


public:
    Texture();
    Texture(const Texture& other);

    bool valid();

    // implementation interface
    int height();
    int width();
    void destroy();
    void draw(float x, float y);
    void load(const char* path);

};


}
}
