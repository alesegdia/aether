#include "sdl_locator.h"

namespace
{
	SDL_Renderer* sRenderer;
}

void aether_sdl_set_renderer(SDL_Renderer* renderer)
{
	sRenderer = renderer;
}

SDL_Renderer* aether_sdl_get_renderer()
{
	return sRenderer;
}
