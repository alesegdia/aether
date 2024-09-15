#pragma once

#ifdef AETHER_USE_ALLEGRO
#include "aether/render/allegro/al_camera.h"
#elif AETHER_USE_SDL
#include "aether/render/sdl/sdl_camera.h"
#elif AETHER_USE_GL
#include "aether/render/gl/gl_camera.h"
#elif AETHER_USE_RAYLIB
#include "aether/render/raylib/rl_camera.h"
#else
#error You must declare what backend to use
#endif

