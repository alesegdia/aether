#include "../font.h"
#include "../../core/handledresourcemanager.h"

#include "gl_locator.h"
#include "gl_texure.h"

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

void Font::Load(const char *path, int size)
{
    assert(IsNotValid());
    TTF_Font* font = TTF_OpenFont(path, size);
    if (font == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
    }
    assert(font != nullptr);
    SetHandle(font_manager.createNewHandle(font));
}

void Font::Destroy()
{
    TTF_CloseFont(fetch(GetHandle()));
    Invalidate();
}

void Font::Print(const char *text, float x, float y, Color c, TextAlign align)
{
    Print(text, x, y, c);
}

void Font::Print(const char *text, float x, float y, float width, float line_height, Color c, bool noalign)
{
    TextData td = CreateTextTexture(text, c);
    td.draw(x, y);
}

TextData Font::CreateTextTexture(const char* text, Color color)
{
    TTF_Font* font = fetch(GetHandle());
    TextData td;
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, { color.r, color.g, color.b, 255 });
    auto texture = aether_sdl_create_texture(SDL_CreateTextureFromSurface(aether_sdl_get_renderer(), surface));
    auto bounds = math::Recti(0, 0, surface->w, surface->h);
    return { texture, bounds };
}


}
}
