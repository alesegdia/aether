#pragma once

#include "../core/handle.h"
#include "color.h"

namespace aether {
namespace graphics {


class Font : public core::Handle
{
public:
    Font() {}

    void load( const char* path, int size );
    void destroy();
    void print( const char* text, float x, float y, Color c = Color() );
    void print(const char* text, float x, float y, float width, float line_height , Color c);

};


}
}
