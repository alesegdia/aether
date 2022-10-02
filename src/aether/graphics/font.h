#pragma once

#include "../core/handle.h"
#include "color.h"
#include "texture.h"

namespace aether {
namespace graphics {

struct TextData
{
    Texture texture;
    math::Recti bounds;
    void draw(float x, float y)
    {
        texture.Draw(x, y);
    }
};

class Font : public core::Handle
{
public:
    Font() {}

    void Load( const char* path, int size );
    void Destroy();
    void Print( const char* text, float x, float y, Color c = Color() );
    void Print(const char* text, float x, float y, float width, float line_height , Color c, bool noalign=false);
    TextData CreateTextTexture(const char* text, Color color);

};


}
}
