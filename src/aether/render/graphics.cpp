#include "aether/graphics/graphics.h"


namespace aether::graphics {


void draw_rectangle(const aether::math::Vec2f& pos, float w, float h, Color c, float thickness)
{
	draw_rectangle(pos.GetX(), pos.GetY(), w, h, c, thickness);
}

void draw_rectangle(const aether::math::Vec2f& pos, const aether::math::Vec2f& size, Color c, float thickness)
{
	draw_rectangle(pos, size.GetX(), size.GetY(), c, thickness);
}

void draw_filled_circle(const aether::math::Vec2f& pos, float radius, Color c)
{
	draw_filled_circle(pos.GetX(), pos.GetY(), radius, c);
}

void draw_filled_circle(const aether::math::Vec2f& pos, float radius, Color c, int alpha)
{
	draw_filled_circle(pos.GetX(), pos.GetY(), radius, c, alpha);
}


}

