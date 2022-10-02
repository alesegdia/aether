#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include <stdio.h>

#include "../texture.h"
#include "../../core/handledresourcemanager.h"

namespace aether {
namespace graphics {


// en un futuro se pueden usar bitset con findfirstfree!
core::HandledResourceManager<ALLEGRO_BITMAP*> texture_manager;

void Texture::Load(const char *path)
{
    assert(IsNotValid());
    ALLEGRO_BITMAP* bitmap = al_load_bitmap(path);
    assert(bitmap != nullptr);
    SetHandle(texture_manager.createNewHandle(bitmap));
}

static ALLEGRO_BITMAP* fetch(int handle)
{
    ALLEGRO_BITMAP* texture = texture_manager.fetchPresentHandle(handle);
    assert(texture != nullptr);
    return texture;
}

int Texture::GetWidth() const
{
    return al_get_bitmap_width(fetch(GetHandle()));
}

int Texture::GetHeight() const
{
    return al_get_bitmap_height(fetch(GetHandle()));
}

void Texture::Destroy()
{
    al_destroy_bitmap(fetch(GetHandle()));
    Invalidate();
}

void Texture::Draw(float x, float y, float rx, float ry, float rw, float rh, aether::graphics::Color color, bool xflip, bool yflip, float centerx, float centery, float angle, float xscale, float yscale) const
{
    al_draw_tinted_scaled_rotated_bitmap_region(fetch(GetHandle()),
                                                rx, ry, rw, rh,
                                                al_map_rgb(color.r, color.g, color.b),
                                                centerx, centery, x, y, xscale, yscale, angle,
                                                (xflip ? ALLEGRO_FLIP_HORIZONTAL : 0) | (yflip ? ALLEGRO_FLIP_VERTICAL : 0));
}


void Texture::Draw(float x, float y) const
{
    al_draw_bitmap(fetch(GetHandle()), x, y, 0);
}

/*
void Texture::draw(float x, float y, float alpha)
{
    al_draw_tinted_bitmap(fetch(handle()), al_map_rgba_f(alpha, alpha, alpha, alpha), x, y, 0);
}
*/

void Texture::DrawScaledCentered(float x, float y,
    float rx, float ry, float rw, float rh,
    aether::graphics::Color color,
    bool xflip, bool yflip,
    float centerx, float centery, float angle, float xscale, float yscale) const
{

}


}
}
