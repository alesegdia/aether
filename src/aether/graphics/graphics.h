#pragma once

#include "color.h"
#include "../math/rect.h"

namespace aether {
namespace graphics {

void clear(float r, float g, float b);
void clear(uint8_t r, uint8_t g, uint8_t b);
void clear(Color c);

/// DRAW_RECTANGLE //////////////////////
void draw_rectangle(float x, float y, float w, float h, Color c, float thickness = 1.0f);
void draw_rectangle(const aether::math::Vec2f& pos, float w, float h, Color c, float thickness = 1.0f);
void draw_rectangle(const aether::math::Vec2f& pos, const aether::math::Vec2f& size, Color c, float thickness = 1.0f);


/// DRAW_FILLED_RECTANGLE //////////////////////
void draw_filled_rectangle(float x, float y, float w, float h, Color c);
void draw_filled_rectangle(const math::Rectf& r, Color c);
void draw_filled_rectangle_centered(const math::Recti& r, Color c);

/// DRAW_FILLED_CIRCLE //////////////////////
void draw_filled_circle(float x, float y, float radius, Color c);
void draw_filled_circle(float x, float y, float radius, Color c, int alpha);

void draw_filled_circle(const aether::math::Vec2f& pos, float radius, Color c);
void draw_filled_circle(const aether::math::Vec2f& pos, float radius, Color c, int alpha);

void draw_line(float x1, float y1, float x2, float y2, Color c, float thickness = 0.0f);
void set_clipping_rect(const aether::math::Recti& r);
void clear_clipping_rect();

}
}
