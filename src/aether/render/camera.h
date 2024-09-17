#pragma once

#ifdef AETHER_USE_ALLEGRO
#include "aether/render/allegro/ALCamera.h"
#elif AETHER_USE_SDL
#include "aether/render/sdl/SDLCamera.h"
#elif AETHER_USE_GL
#include "aether/render/gl/GLCamera.h"
#elif AETHER_USE_RAYLIB
#include "aether/render/raylib/RLCamera.h"
#else
#error You must declare what backend to use
#endif

