#include <stdio.h>

#include <SDL.h>

#include "sdl_locator.h"
#include "../texture.h"
#include "../../core/handledresourcemanager.h"

namespace aether {
namespace graphics {

core::HandledResourceManager<SDL_Surface*> texture_manager;

void Texture::load(const char *path)
{

}

int Texture::width() const
{
    return 0;
}

int Texture::height() const
{
    return 0;
}

void Texture::destroy()
{

}

void Texture::draw(float x, float y, float rx, float ry, float rw, float rh, aether::graphics::Color color, bool xflip, bool yflip, float centerx, float centery, float angle, float xscale, float yscale) const
{

}


void Texture::draw(float x, float y) const
{

}

void Texture::draw(float x, float y, float alpha)
{

}

}
}
