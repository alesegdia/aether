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

    Uint32 windowFlags = SDL_WINDOW_SHOWN;


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


    if (IsOpenGLActivated())
    {
        SDL_GL_LoadLibrary(nullptr);
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        windowFlags |= SDL_WINDOW_OPENGL;
    }

    m_window = SDL_CreateWindow("WindowName",
								 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							     GetApplicationWindowScreenWidth(), GetApplicationWindowScreenHeight(), windowFlags);
    if(!m_window) {
        fprintf(stderr, "failed to create display! %s\n", SDL_GetError());
        return -1;
    }

    if(IsOpenGLActivated())
    {
	    glContext = SDL_GL_CreateContext(m_window);
        if(glContext == NULL)
        {
            fprintf(stderr, "failed to create GL context! %s\n", SDL_GetError());
            return -1;
        }

        // Check OpenGL properties
        printf("OpenGL loaded\n");
        gladLoadGL((GLADloadfunc) SDL_GL_GetProcAddress);
        printf("Vendor:   %s\n", glGetString(GL_VENDOR));
        printf("Renderer: %s\n", glGetString(GL_RENDERER));
        printf("Version:  %s\n", glGetString(GL_VERSION));

        // Use v-sync
        SDL_GL_SetSwapInterval(1);

        // Disable depth test and face culling.
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);

        int w, h;
        SDL_GetWindowSize(m_window, &w, &h);
        glViewport(0, 0, w, h);
        glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
    }
    else
    {
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
        aether_sdl_set_renderer(m_renderer);

        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);
        SDL_RenderClear(m_renderer);
    }

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
    if(m_renderer != nullptr)
    {
        SDL_RenderPresent(m_renderer);
    }
}

void SDLApplication::Deinit()
{
    if(m_renderer != nullptr)
    {
        SDL_DestroyRenderer(m_renderer);
    }

    SDL_DestroyWindow(m_window);
    IMG_Quit();
    SDL_Quit();
}

void SDLApplication::PreUpdate()
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

void SDLApplication::PostUpdate()
{
    _input_post_update();
}

void SDLApplication::GrabMouse()
{
    SDL_SetWindowGrab(m_window, SDL_TRUE);
}

}
}
