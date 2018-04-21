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

}
}
