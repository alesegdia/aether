#include "../graphics.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

namespace aether {
namespace graphics {


void clear(float r, float g, float b)
{
    al_clear_to_color(al_map_rgb(r, g, b));
}

void draw_rectangle(float x1, float y1, float x2, float y2, Color c, float thickness)
{
    al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(c.r, c.g, c.b), thickness);
}

void draw_filled_rectangle(float x1, float y1, float x2, float y2, Color c)
{
    al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(c.r, c.g, c.b));
}

void draw_filled_rectangle(const math::Rectf& r, Color c)
{
    al_draw_filled_rectangle(r.x1(), r.y1(), r.x2(), r.y2(), al_map_rgb(c.r, c.g, c.b));
}

void draw_filled_rectangle(const math::Recti& r, Color c)
{
    al_draw_filled_rectangle(r.x1(), r.y1(), r.x2(), r.y2(), al_map_rgb(c.r, c.g, c.b));
}

void draw_filled_circle(float x, float y, float radius, Color c)
{
    al_draw_filled_circle(x, y, radius, al_map_rgb(c.r, c.g, c.b));
}

void draw_filled_circle(float x, float y, float radius, Color c, int alpha)
{
    al_draw_filled_circle(x, y, radius, al_map_rgba(alpha, alpha, alpha, alpha));
}

void draw_line(float x1, float y1, float x2, float y2, Color c, float thickness)
{
    al_draw_line(x1, y1, x2, y2, al_map_rgb(c.r, c.g, c.b), thickness);
}


}
}
