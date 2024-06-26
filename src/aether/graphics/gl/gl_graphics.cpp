#include "../graphics.h"

#include "gl_locator.h"

namespace aether {
namespace graphics {


void clear(float r, float g, float b)
{
    aether::graphics::Color c(r, g, b);
    SDL_SetRenderDrawColor(aether_sdl_get_renderer(), c.r, c.g, c.b, 0);
    SDL_RenderClear(aether_sdl_get_renderer());
}

void draw_rectangle(float x1, float y1, float x2, float y2, Color c, float thickness)
{

}

void draw_filled_rectangle(float x1, float y1, float x2, float y2, Color c)
{
    math::Recti rect = { int(x1), int(y1), int(x2 - x1), int(y2 - y1) };
    draw_filled_rectangle(rect, c);
}

void draw_filled_rectangle(const math::Recti& rect, Color c)
{
    SDL_SetRenderDrawColor(aether_sdl_get_renderer(), c.r, c.g, c.b, c.a);
    SDL_Rect sdlrect = { rect.x(), rect.y(), rect.w(), rect.h() };
    SDL_RenderFillRect(aether_sdl_get_renderer(), &sdlrect);
}

void draw_filled_rectangle(const math::Rectf& r, Color c)
{
    SDL_SetRenderDrawColor(aether_sdl_get_renderer(), c.r, c.g, c.b, c.a);
    SDL_Rect sdlrect = { r.x(), r.y(), r.w(), r.h() };
    SDL_RenderFillRect(aether_sdl_get_renderer(), &sdlrect);
}

void draw_filled_rectangle_centered(const math::Recti& r, Color c)
{

}

void draw_filled_rectangle_centered(const math::Rectf& r, Color c)
{

}

void draw_filled_circle(float x, float y, float radius, Color c)
{

}

void draw_filled_circle(float x, float y, float radius, Color c, int alpha)
{

}

void draw_line(float x1, float y1, float x2, float y2, Color c, float thickness)
{

}


}
}
