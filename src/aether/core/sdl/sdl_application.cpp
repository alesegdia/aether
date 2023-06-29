#include "sdl_application.h"
#include "sdl_keycode.h"
#include "../../graphics/sdl/sdl_locator.h"
#include "aether/core/logger.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

namespace aether {
namespace core {

SDLApplication::SDLApplication(int sw, int sh)
    : ApplicationBase(sw, sh)
{

}

int SDLApplication::AppImplementationInit(int argc, char **argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        Logger::LogError("Failed to initialize SDL video.");
        return -1;
    }
    else
    {
        Logger::LogMsg("SDL video initialized successfully.");
    }

	int flags = IMG_INIT_PNG;
    if(IMG_Init(flags) & flags != flags) {
        Logger::LogError("Failed to initialize SDL image.");
        return -1;
    }
    else
    {
        Logger::LogMsg("SDL video initialized successfully.");
    }

	TTF_Init();

    m_display = SDL_CreateWindow("WindowName",
								 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							     GetApplicationWindowScreenWidth(), GetApplicationWindowScreenHeight(), SDL_WINDOW_SHOWN);
    if(!m_display) {
        fprintf(stderr, "failed to create display! %s\n", SDL_GetError());
        return -1;
    }

	m_renderer = SDL_CreateRenderer(m_display, -1, SDL_RENDERER_ACCELERATED);
    aether_sdl_set_renderer(m_renderer);

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
    SDL_RenderClear(m_renderer);

    // initialize input
    //Input::Initialize();

    /*
    SDL_version version;
    SDL_GetVersion(&version);
    printf("SDL Version: %u.%u.%u", version.major, version.minor, version.patch);
    */

    return 0;
}

void SDLApplication::PreRender()
{

}

void SDLApplication::PostRender()
{
    SDL_RenderPresent(m_renderer);
}

void aether::core::SDLApplication::Deinit()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_display);
    IMG_Quit();
    SDL_Quit();
}

void aether::core::SDLApplication::PreUpdate()
{
    SDL_Event ev;
    while( SDL_PollEvent(&ev) )
    {
        if(ev.type == SDL_QUIT)
        {
            Close();
        }
        else if(ev.type == SDL_KEYDOWN)
        {
            _notify_key_down((KeyCode)ev.key.keysym.scancode);
        }
        else if(ev.type == SDL_KEYUP)
        {
            _notify_key_up((KeyCode)ev.key.keysym.scancode);
        }
        else if( ev.type == SDL_MOUSEBUTTONDOWN)
        {
            _notify_mouse_button_down((MouseButton)ev.button.button);
        }
    }

    // setup mouse state
    int x, y;
    auto buttons = SDL_GetMouseState(&x, &y);
    MouseState& aether_mouse_state = _get_mouse_state();
    aether_mouse_state.x = x;
    aether_mouse_state.y = y;
    aether_mouse_state.buttons = buttons;
}

void aether::core::SDLApplication::PostUpdate()
{
    _input_post_update();
}

void aether::core::SDLApplication::GrabMouse()
{
    SDL_SetWindowGrab(m_display, SDL_TRUE);
}

}
}
