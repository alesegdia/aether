#include <allegro5/allegro_font.h>

#include "../font.h"
#include "../../core/handledresourcemanager.h"


namespace aether {
namespace graphics {

static core::HandledResourceManager<ALLEGRO_FONT*> font_manager;

static ALLEGRO_FONT* fetch(int handle)
{
    ALLEGRO_FONT* font = font_manager.fetch(handle);
    assert(font != nullptr);
    return font;
}

void Font::load(const char *path, int size)
{
    assert(notValid());
    ALLEGRO_FONT* font = al_load_font(path, size, 0);
    assert(font != nullptr);
    handle(font_manager.setNextHandle(font));
}

void Font::destroy()
{
    al_destroy_font(fetch(handle()));
    invalidate();
}

void Font::print(const char *text, float x, float y, Color c)
{
    ALLEGRO_FONT* font = fetch(handle());
    al_draw_text(font, al_map_rgb(c.r, c.g, c.b), x, y, 0, text);
}


}
}
