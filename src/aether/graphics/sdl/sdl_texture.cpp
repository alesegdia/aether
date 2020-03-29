#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>

#include "sdl_locator.h"
#include "../texture.h"
#include "../../core/handledresourcemanager.h"

namespace aether {
namespace graphics {

core::HandledResourceManager<SDL_Texture*> texture_manager;

static SDL_Texture* fetch(int handle)
{
    SDL_Texture* texture = texture_manager.fetchPresentHandle(handle);
    assert(texture != nullptr);
    return texture;
}

void Texture::load(const char* path)
{
    assert(notValid());
    auto* renderer = aether_sdl_get_renderer();
    assert(renderer);
    auto* texture = IMG_LoadTexture(renderer, path);
    assert(texture);
    handle(texture_manager.createNewHandle(texture));
}

int Texture::width() const
{
    auto* texture = fetch(handle());
    int w;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, nullptr);
    return w;
}

int Texture::height() const
{
    auto* texture = fetch(handle());
    int h;
    SDL_QueryTexture(texture, nullptr, nullptr, nullptr, &h);
    return h;
}

void Texture::destroy()
{
    SDL_DestroyTexture(fetch(handle()));
}

void Texture::draw(float x, float y,
                   float rx, float ry, float rw, float rh,
                   aether::graphics::Color color,
                   bool xflip, bool yflip,
                   float centerx, float centery,
                   float angle,
                   float xscale, float yscale) const
{
    SDL_Texture* texture = texture_manager.fetchPresentHandle(handle());
    SDL_Renderer* renderer = aether_sdl_get_renderer();
    SDL_Point center{ int(centerx), int(centery) };
    SDL_Rect srcRect{ int(rx), int(ry), int(rw), int(rh) };
    SDL_Rect dstRect{ int(x), int(y), int(rw * xscale), int(rh * yscale) };
    SDL_RendererFlip flip = SDL_RendererFlip((xflip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE) | (yflip ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE));
    SDL_RenderCopyEx(renderer, texture, &srcRect, &dstRect, angle, &center, flip);
}

void Texture::draw(float x, float y) const
{
    draw(x, y, 1.0f);
}

void Texture::draw(float x, float y, float alpha) const
{
    draw(x, y, 0.0f, 0.0f, float(width()), float(height()), { 1.0f, 1.0f, 1.0f }, false, false, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
}

}
}
