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

void Texture::Load(const char* path)
{
    assert(IsNotValid());
    auto* renderer = aether_sdl_get_renderer();
    assert(renderer);
    auto* texture = IMG_LoadTexture(renderer, path);
    printf("Oh My Goodness, an error : %s", IMG_GetError());
    assert(texture);
    SetHandle(texture_manager.createNewHandle(texture));
}

int Texture::GetWidth() const
{
    auto* texture = fetch(GetHandle());
    int w;
    SDL_QueryTexture(texture, nullptr, nullptr, &w, nullptr);
    return w;
}

int Texture::GetHeight() const
{
    auto* texture = fetch(GetHandle());
    int h;
    SDL_QueryTexture(texture, nullptr, nullptr, nullptr, &h);
    return h;
}

void Texture::Destroy()
{
    if(IsValid())
        SDL_DestroyTexture(fetch(GetHandle()));
}

void Texture::Draw(float x, float y,
                   float rx, float ry, float rw, float rh,
                   aether::graphics::Color color,
                   bool xflip, bool yflip,
                   float centerx, float centery,
                   float angle,
                   float xscale, float yscale) const
{
    SDL_Texture* texture = texture_manager.fetchPresentHandle(GetHandle());
    SDL_Renderer* renderer = aether_sdl_get_renderer();
    SDL_Point center{ int(centerx), int(centery) };
    SDL_Rect srcRect{ int(rx), int(ry), int(rw), int(rh) };
    SDL_Rect dstRect{ int(x), int(y), int(rw * xscale), int(rh * yscale) };
    SDL_RendererFlip flip = SDL_RendererFlip((xflip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE) | (yflip ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE));
    SDL_RenderCopyEx(renderer, texture, &srcRect, &dstRect, angle, NULL, flip);
}

void Texture::DrawScaledCentered(float x, float y,
    float rx, float ry, float rw, float rh,
    aether::graphics::Color color,
    bool xflip, bool yflip,
    float centerx, float centery,
    float angle,
    float xscale, float yscale) const
{
    SDL_Texture* texture = texture_manager.fetchPresentHandle(GetHandle());
    SDL_Renderer* renderer = aether_sdl_get_renderer();
    SDL_Point center{ int(centerx), int(centery) };
    SDL_Rect srcRect{ int(rx), int(ry), int(rw), int(rh) };
    int dstW = int(rw * xscale);
    int dstH = int(rh * yscale);
    SDL_Rect dstRect{ int(x) - dstW / 2, int(y) - dstW / 2, dstW, dstH };
    SDL_RendererFlip flip = SDL_RendererFlip((xflip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE) | (yflip ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE));
    SDL_RenderCopyEx(renderer, texture, &srcRect, &dstRect, angle, NULL, flip);
}



void Texture::Draw(float x, float y) const
{
    Draw(x, y, 1.0f);
}

void Texture::Draw(float x, float y, float alpha) const
{
    Draw(x, y, 0.0f, 0.0f, float(GetWidth()), float(GetHeight()), { 1.0f, 1.0f, 1.0f }, false, false, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f);
}

}
}

aether::graphics::Texture aether_sdl_create_texture(SDL_Texture* texture)
{
    auto handle = aether::graphics::texture_manager.createNewHandle(texture);
    return aether::graphics::Texture(handle);
}

