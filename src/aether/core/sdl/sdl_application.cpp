#include "sdl_application.h"
#include "sdl_keycode.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

namespace aether {
namespace core {

SDLApplication::SDLApplication(int sw, int sh)
    : ApplicationBase(sw, sh)
{

}

int SDLApplication::init(int argc, char **argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "failed to initialize SDL video!\n");
        return -1;
    }

	int flags = IMG_INIT_PNG;
    if(IMG_Init(flags) & flags != flags) {
        fprintf(stderr, "failed to initialize SDL image!\n");
        return -1;
    }

	TTF_Init();

    m_display = SDL_CreateWindow("WindowName",
								 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							     screenWidth(), screenHeight(), SDL_WINDOW_SHOWN);
    if(!m_display) {
        fprintf(stderr, "failed to create display! %s\n", SDL_GetError());
        return -1;
    }

	m_renderer = SDL_CreateRenderer(m_display, -1, SDL_RENDERER_ACCELERATED);

    al_clear_to_color(al_map_rgb(255, 0, 255));
    al_set_target_bitmap(al_get_backbuffer(m_display));

    al_clear_to_color(al_map_rgb(0,0,0));

    al_set_target_bitmap(al_get_backbuffer(m_display));

    al_set_new_display_option(ALLEGRO_VSYNC, 2, 1000);

    // initialize input
    //Input::Initialize();

    SDL_version version;
    SDL_GetVersion(&version);
    printf("SDL Version: %u.%u.%u", version.major, version.minor, version.patch);

    return 0;
}

void SDLApplication::preRender()
{
    al_set_target_bitmap(al_get_backbuffer(m_display));
}

void SDLApplication::postRender()
{
    al_flip_display();
}

void aether::core::SDLApplication::cleanup()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_display);
    IMG_Quit();
    SDL_Quit();
}

void aether::core::SDLApplication::preUpdate()
{
    SDL_Event ev;
    while( SDL_PollEvent(&ev) )
    {
        if(ev.type == SDL_QUIT)
        {
            close();
        }
        else if(ev.type == SDL_KEYDOWN)
        {
            _notify_key_down((KeyCode)ev.key.keysym.sym);
        }
        else if(ev.type == SDL_KEYUP)
        {
            _notify_key_up((KeyCode)ev.key.keysym.sym);
        }
        else if( ev.type == SDL_MOUSEBUTTONDOWN)
        {
            _notify_mouse_button_down(ev.button.button);
        }
    }

    // setup mouse state
    int x, y;
    auto buttons = SDL_GetMouseState(&x, &y);
    MouseState& aether_mouse_state = _get_mouse_state();
    aether_mouse_state.x = allegro_mouse_state.x;
    aether_mouse_state.y = allegro_mouse_state.y;
    aether_mouse_state.buttons = allegro_mouse_state.buttons;
}

void aether::core::SDLApplication::postUpdate()
{
    _input_post_update();
}

void aether::core::SDLApplication::grabMouse()
{
    SDL_SetWindowGrab(m_display, SDL_TRUE);
}

}
}
