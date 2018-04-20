#include <allegro5/allegro5.h>

#include <allegro5/allegro_image.h>

#include <stdio.h>

#include "../texture.h"

namespace aether {
namespace graphics {

// en un futuro se pueden usar bitset con findfirstfree!

static constexpr size_t NUM_TEXTURES = 64;

ALLEGRO_BITMAP* textures[NUM_TEXTURES];
size_t num_used_textures = 0;

Texture::Texture()
{
    m_handle = -1;
}

void Texture::load(const char *path)
{
    printf("loading\n");
    ALLEGRO_BITMAP* bitmap = al_load_bitmap(path);
    printf("%d\n", m_handle);
    assert(m_handle == -1);
    assert(bitmap != nullptr);
    assert(num_used_textures + 1 < NUM_TEXTURES);
    int handle = num_used_textures;
    num_used_textures++;
    textures[handle] = bitmap;
    m_handle = handle;
}

static ALLEGRO_BITMAP* fetch(int handle)
{
    assert(handle >= 0);
    assert(handle < num_used_textures);
    ALLEGRO_BITMAP* texture = textures[handle];
    assert(texture != nullptr);
    return texture;
}

int Texture::width()
{
    return al_get_bitmap_width(fetch(m_handle));
}

int Texture::height()
{
    return al_get_bitmap_height(fetch(m_handle));
}

void Texture::destroy()
{
    al_destroy_bitmap(fetch(m_handle));
    m_handle = -1;
}

void Texture::draw(float x, float y)
{
    al_draw_bitmap(fetch(m_handle), x, y, 0);
}


}
}
