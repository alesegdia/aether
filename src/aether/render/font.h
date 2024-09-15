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

enum TextAlign
{
	Left,
    Center,
    Right
};

class Font : public core::Handle
{
public:
    Font() {}

    void Load( const char* path, int size );
    void Destroy();
    void Print(const char* text, float x, float y, Color c = Color::White, TextAlign align = Left);
    void Print(const char* text, float x, float y, float width, float line_height, Color c, bool noalign = false);

    void Print(const std::string& text, float x, float y, Color c = Color::White, TextAlign align = Left)
    {
        Print(text.c_str(), x, y, c, align);
    }
    void Print(const std::string& text, float x, float y, float width, float line_height, Color c, bool noalign = false)
    {
        Print(text, x, y, width, line_height, c, noalign);
    }

    int GetWidthForText(const char* text);
    TextData CreateTextTexture(const char* text, Color color);

};


}
}
