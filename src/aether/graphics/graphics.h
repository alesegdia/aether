#pragma once

#include "color.h"
#include "../math/vec.h"

namespace aether {
namespace graphics {

void clear(float r, float g, float b);
void draw_rectangle(float x1, float y1, float x2, float y2, Color c, float thickness = 1.0f);

void draw_filled_rectangle(float x1, float y1, float x2, float y2, Color c);
void draw_filled_rectangle(const math::Rectf& r, Color c);
void draw_filled_rectangle(const math::Recti& r, Color c);
void draw_filled_circle(float x, float y, float radius, Color c);
void draw_filled_circle(float x, float y, float radius, Color c, int alpha);

}
}
