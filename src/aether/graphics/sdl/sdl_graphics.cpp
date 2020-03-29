#include "../graphics.h"

#include "sdl_locator.h"

namespace aether {
namespace graphics {


void clear(float r, float g, float b)
{
    SDL_SetRenderDrawColor(aether_sdl_get_renderer(), r, g, b, 0);
    SDL_RenderClear(aether_sdl_get_renderer());
}

void draw_rectangle(float x1, float y1, float x2, float y2, Color c, float thickness)
{

}

void draw_filled_rectangle(float x1, float y1, float x2, float y2, Color c)
{

}

void draw_filled_rectangle(const math::Rectf& r, Color c)
{

}

void draw_filled_rectangle(const math::Recti& r, Color c)
{

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
