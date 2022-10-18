#pragma once

#ifdef AETHER_USE_ALLEGRO
#include "core/allegro/al_application.h"
#include "graphics/allegro/al_camera.h"
#elif AETHER_USE_3DS
	#include "core/3ds/3ds_application.h"
#elif AETHER_USE_SDL
	#include "core/sdl/sdl_application.h"
#else
	#error You must declare what backend to use
#endif

