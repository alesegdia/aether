#include "../font.h"
#include "../../core/handledresourcemanager.h"

#include "sdl_locator.h"
#include "sdl_texure.h"

#include <SDL_ttf.h>

namespace aether {
namespace graphics {

core::HandledResourceManager<TTF_Font*> font_manager;

static TTF_Font* fetch(int handle)
{
    TTF_Font* font = font_manager.fetchPresentHandle(handle);
    assert(font != nullptr);
    return font;
}

void Font::load(const char *path, int size)
{
    assert(notValid());
    TTF_Font* font = TTF_OpenFont(path, size);
    if (font == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
    }
    assert(font != nullptr);
    handle(font_manager.createNewHandle(font));
}

void Font::destroy()
{
    TTF_CloseFont(fetch(handle()));
    invalidate();
}

void Font::print(const char *text, float x, float y, Color c)
{

}

void Font::print(const char *text, float x, float y, float width, float line_height, Color c, bool noalign)
{

}

TextData Font::createTextTexture(const char* text, Color color)
{
    TTF_Font* font = fetch(handle());
    TextData td;
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, { color.r, color.g, color.b, 255 });
    auto texture = aether_sdl_create_texture(SDL_CreateTextureFromSurface(aether_sdl_get_renderer(), surface));
    auto bounds = math::Recti(0, 0, surface->w, surface->h);
    return { texture, bounds };
}


}
}
