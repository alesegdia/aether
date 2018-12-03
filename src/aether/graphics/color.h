#pragma once

#include <cstdint>

namespace aether {
namespace graphics {


struct Color
{
    Color(uint8_t r, uint8_t g, uint8_t b)
        : r(r)
        , g(g)
        , b(b)
    {

    }

    Color(float r, float g, float b)
        : r(uint8_t(0xFF * r))
        , g(uint8_t(0xFF * g))
        , b(uint8_t(0xFF * b))
    {

    }

    Color()
    {

    }

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

};


}
}
