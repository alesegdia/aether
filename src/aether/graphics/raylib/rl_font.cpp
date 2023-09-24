#include <raylib.h>

#include "../font.h"
#include "../../core/handledresourcemanager.h"


namespace aether {
namespace graphics {

    struct RaylibFont
    {
        ::Font font;
        int size;
    };

static core::HandledResourceManager<RaylibFont> font_manager;

static RaylibFont fetch(int handle)
{
    RaylibFont font = font_manager.fetchPresentHandle(handle);
    return font;
}

void Font::Load(const char *path, int size)
{
    assert(IsNotValid());
    ::Font font = LoadFontEx(path, size, NULL, 0);
    RaylibFont f = { font, size };
    SetHandle(font_manager.createNewHandle(f));
}

void Font::Destroy()
{
    UnloadFont(fetch(GetHandle()).font);
    Invalidate();
}

void Font::Print(const char *text, float x, float y, Color c, TextAlign align)
{
	RaylibFont font = fetch(GetHandle());
	DrawTextEx(font.font, text, { x, y }, font.size, 0, { c.r, c.g, c.b, c.a });
	//DrawText(font.font, text, x, y, font.font.baseSize, { c.r, c.g, c.b, c.a });
}

void Font::Print(const char *text, float x, float y, float width, float line_height, Color c, bool noalign)
{
    Print(text, x, y, c, TextAlign::Left);
}

TextData Font::CreateTextTexture(const char* text, Color color)
{
    assert(false);
    return {};
}


}
}
