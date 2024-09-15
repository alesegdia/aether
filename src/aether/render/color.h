#pragma once

#include <cstdint>

namespace aether::render {



struct Color
{

	static const Color White;
	static const Color Black;
	static const Color Gray;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Cyan;
	static const Color Magenta;
	static const Color Yellow;

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {

    }

    Color(float r, float g, float b, float a = 1.0f)
        : r(uint8_t(0xFF * r))
        , g(uint8_t(0xFF * g))
        , b(uint8_t(0xFF * b))
        , a(uint8_t(0xFF * a))
    {

    }

    Color()
    {

    }

    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;

};


}
