#pragma once


namespace aether {
namespace graphics {


struct Color
{
    Color(float r, float g, float b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    Color()
    {

    }

    float r = 0;
    float g = 0;
    float b = 0;

};


}
}
