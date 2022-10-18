#pragma once

#ifdef AETHER_USE_ALLEGRO
#include "aether/graphics/allegro/al_camera.h"
#elif AETHER_USE_3DS

#elif AETHER_USE_SDL

#else
#error You must declare what backend to use
#endif

