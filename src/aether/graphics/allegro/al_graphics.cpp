#include "../graphics.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

namespace aether {
namespace graphics {


void clear(float r, float g, float b)
{
    clear(uint8_t(r * 255), uint8_t(g * 255), uint8_t(b * 255));
}

void clear(uint8_t r, uint8_t g, uint8_t b)
{
	al_clear_to_color(al_map_rgb(r, g, b));
}

void clear(Color c)
{
	clear(c.r, c.g, c.b);
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

void draw_filled_rectangle_centered(const math::Recti& r, Color c)
{
    al_draw_filled_rectangle(r.x1() - r.w() / 2, r.y1() - r.h() / 2, r.x2() - r.w() / 2, r.y2() - r.h() / 2, al_map_rgb(c.r, c.g, c.b));
}

void draw_filled_rectangle_centered(const math::Rectf& r, Color c)
{
    al_draw_filled_rectangle(r.x1() - r.w() / 2, r.y1() - r.h() / 2, r.x2() - r.w() / 2, r.y2() - r.h() / 2, al_map_rgb(c.r, c.g, c.b));
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

namespace
{
    aether::math::Recti base_clipping_rect;
    bool clipping_rect_in_use = false;
}

void set_clipping_rect(const aether::math::Recti& r)
{
    if (!clipping_rect_in_use)
    {
        int x, y, w, h;
        al_get_clipping_rectangle(&x, &y, &w, &h);
        base_clipping_rect.position(x, y);
        base_clipping_rect.size(w, h);
        clipping_rect_in_use = true;
    }
    al_set_clipping_rectangle(r.x(), r.y(), r.w(), r.h());
}

void clear_clipping_rect()
{
    if (clipping_rect_in_use)
    {
        const auto& r = base_clipping_rect;
        al_set_clipping_rectangle(r.x(), r.y(), r.w(), r.h());
        clipping_rect_in_use = false;
    }
}


}
}
