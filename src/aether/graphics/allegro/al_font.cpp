#include <allegro5/allegro_font.h>

#include "../font.h"
#include "../../core/handledresourcemanager.h"


namespace aether {
namespace graphics {

static core::HandledResourceManager<ALLEGRO_FONT*> font_manager;

static ALLEGRO_FONT* fetch(int handle)
{
    ALLEGRO_FONT* font = font_manager.fetchPresentHandle(handle);
    assert(font != nullptr);
    return font;
}

void Font::Load(const char *path, int size)
{
    assert(IsNotValid());
    ALLEGRO_FONT* font = al_load_font(path, size, 0);
    assert(font != nullptr);
    SetHandle(font_manager.createNewHandle(font));
}

void Font::Destroy()
{
    al_destroy_font(fetch(GetHandle()));
    Invalidate();
}

void Font::Print(const char *text, float x, float y, Color c, TextAlign align)
{
    int flags = ALLEGRO_ALIGN_CENTRE;
    switch(align)
    {
    case TextAlign::Left: flags = ALLEGRO_ALIGN_LEFT; break;
    case TextAlign::Right: flags = ALLEGRO_ALIGN_RIGHT; break;
    }
    ALLEGRO_FONT* font = fetch(GetHandle());
    al_draw_text(font, al_map_rgb(c.r, c.g, c.b), x, y, flags, text);
}

void Font::Print(const char *text, float x, float y, float width, float line_height, Color c, bool noalign)
{
    ALLEGRO_FONT* font = fetch(GetHandle());
    if( noalign )
    {
        al_draw_multiline_text(font, al_map_rgb(c.r, c.g, c.b), x, y, width, line_height, ALLEGRO_ALIGN_LEFT, text);
    }
    else
    {
        al_draw_multiline_text(font, al_map_rgb(c.r, c.g, c.b), x, y, width, line_height, ALLEGRO_ALIGN_CENTER, text);
    }
}

TextData Font::CreateTextTexture(const char* text, Color color)
{
    assert(false);
    return {};
}


}
}
