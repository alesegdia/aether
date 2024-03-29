#pragma once

#ifdef AETHER_USE_ALLEGRO
#include "aether/graphics/allegro/al_camera.h"
#elif AETHER_USE_SDL
#include "aether/graphics/sdl/sdl_camera.h"
#elif AETHER_USE_GL
#include "aether/graphics/gl/gl_camera.h"
#elif AETHER_USE_RAYLIB
#include "aether/graphics/raylib/rl_camera.h"
#else
#error You must declare what backend to use
#endif

