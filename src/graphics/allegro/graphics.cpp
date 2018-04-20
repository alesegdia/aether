#include "../graphics.h"

#include <allegro5/allegro5.h>

namespace aether {
namespace graphics {

void clear(float r, float g, float b)
{
    al_clear_to_color(al_map_rgb(r, g, b));
}

}
}
