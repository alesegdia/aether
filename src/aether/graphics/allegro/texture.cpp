#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include <stdio.h>

#include "../texture.h"
#include "../../core/handledresourcemanager.h"

namespace aether {
namespace graphics {


// en un futuro se pueden usar bitset con findfirstfree!
core::HandledResourceManager<ALLEGRO_BITMAP*> texture_manager;

void Texture::load(const char *path)
{
    assert(notValid());
    ALLEGRO_BITMAP* bitmap = al_load_bitmap(path);
    assert(bitmap != nullptr);
    handle(texture_manager.setNextHandle(bitmap));
}

static ALLEGRO_BITMAP* fetch(int handle)
{
    ALLEGRO_BITMAP* texture = texture_manager.fetch(handle);
    assert(texture != nullptr);
    return texture;
}

int Texture::width()
{
    return al_get_bitmap_width(fetch(handle()));
}

int Texture::height()
{
    return al_get_bitmap_height(fetch(handle()));
}

void Texture::destroy()
{
    al_destroy_bitmap(fetch(handle()));
    invalidate();
}

void Texture::draw(float x, float y)
{
    al_draw_bitmap(fetch(handle()), x, y, 0);
}

void Texture::draw(float x, float y, float alpha)
{
    al_draw_tinted_bitmap(fetch(handle()), al_map_rgba_f(alpha, alpha, alpha, alpha), x, y, 0);
}


}
}
