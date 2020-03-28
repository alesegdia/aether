#include "sdl_application.h"

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

    m_eventQueue = al_create_event_queue();
    if(!m_eventQueue) {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_display(m_display);
        return -1;
    }

    if (!al_reserve_samples(3)){
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }

    al_register_event_source(m_eventQueue, al_get_display_event_source(m_display));
    al_register_event_source(m_eventQueue, al_get_keyboard_event_source());
    al_register_event_source(m_eventQueue, al_get_mouse_event_source());

    al_clear_to_color(al_map_rgb(0,0,0));

    al_set_target_bitmap(al_get_backbuffer(m_display));

    al_set_new_display_option(ALLEGRO_VSYNC, 2, 1000);

    // initialize input
    //Input::Initialize();

    uint32_t version = al_get_allegro_version();
    int major = version >> 24;
    int minor = (version >> 16) & 255;
    int revision = (version >> 8) & 255;
    int release = version & 255;
    //printf("Allegro %d.%d.%d.%d\n", major, minor, revision, release);

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
    al_destroy_display(m_display);
    al_shutdown_image_addon();
    al_shutdown_primitives_addon();
    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
    al_uninstall_audio();
    al_uninstall_keyboard();
    al_uninstall_mouse();
}

void aether::core::SDLApplication::preUpdate()
{
    ALLEGRO_EVENT ev;
    while( al_get_next_event(m_eventQueue, &ev) )
    {
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            close();
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            _notify_key_down((KeyCode)ev.keyboard.keycode);
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            _notify_key_up((KeyCode)ev.keyboard.keycode);
        }
        else if( ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN )
        {
            _notify_mouse_button_down((MouseButton)ev.mouse.button);
        }
    }

    // setup mouse state
    ALLEGRO_MOUSE_STATE allegro_mouse_state;
    al_get_mouse_state(&allegro_mouse_state);
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
    assert(al_grab_mouse(m_display));
}

}
}
