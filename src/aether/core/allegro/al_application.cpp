#include "al_application.h"

#include <iostream>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <imgui.h>
#include <imgui_impl_allegro5.h>
#include <enet/enet.h>

#include <iostream>

namespace aether {
namespace core {

AllegroApplication::AllegroApplication(int sw, int sh)
    : ApplicationBase(sw, sh)
{

}

AllegroApplication::~AllegroApplication()
{

}

int AllegroApplication::Init(int argc, char **argv)
{
    al_register_trace_handler([](const char* message) {
        std::cout << "ALLEGRO MESSAGE: " << message;
        });

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }

    if(!al_install_mouse()) {
        fprintf(stderr, "failed to initialize the mouse!\n");
        return -1;
    }

    if(!al_init_image_addon()) {
        fprintf(stderr, "failed to initialize image addon!\n");
        return -1;
    }

    if (!al_init_primitives_addon()) {
        fprintf(stderr, "failed to initialize primitives addon!\n");
        return -1;
    }


    if (!al_init_acodec_addon()) {
        fprintf(stderr, "failed to initialize audio codecs!\n");
        return -1;
    }

    if (!al_install_audio()) {
        fprintf(stderr, "failed to initialize audio!\n");
        return -1;
    }

    if (!al_reserve_samples(3)) {
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }

    al_init_font_addon();

    if(!al_init_ttf_addon()) {
        fprintf(stderr, "failed to initialize ttf addon!\n");
        return -1;
    }

    al_set_new_display_flags(ALLEGRO_DIRECT3D_INTERNAL);
    al_set_new_display_option(ALLEGRO_VSYNC, 2, 1000);
    m_display = al_create_display(GetApplicationWindowScreenWidth(), GetApplicationWindowScreenHeight());
    if(!m_display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    al_clear_to_color(al_map_rgb(255, 0, 255));
    al_set_target_bitmap(al_get_backbuffer(m_display));

    m_eventQueue = al_create_event_queue();
    if(!m_eventQueue) {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_display(m_display);
        return -1;
    }

    al_register_event_source(m_eventQueue, al_get_display_event_source(m_display));
    al_register_event_source(m_eventQueue, al_get_keyboard_event_source());
    al_register_event_source(m_eventQueue, al_get_mouse_event_source());


    al_set_target_bitmap(al_get_backbuffer(m_display));

    al_set_new_display_option(ALLEGRO_VSYNC, 2, 1000);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplAllegro5_Init(m_display);


    // initialize input
    //Input::Initialize();

    if (enet_initialize() != 0)
    {
        std::cerr << "Couldn't initialize enet.\n" << std::endl;
        return -1;
    }

    atexit(enet_deinitialize);


    uint32_t version = al_get_allegro_version();
    int major = version >> 24;
    int minor = (version >> 16) & 255;
    int revision = (version >> 8) & 255;
    int release = version & 255;
    printf("Allegro %d.%d.%d.%d\n", major, minor, revision, release);
    // al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA);
    return 0;
}

void AllegroApplication::PreRender()
{
    al_set_target_bitmap(al_get_backbuffer(m_display));
    ImGui_ImplAllegro5_NewFrame();
    ImGui::NewFrame();
}

void AllegroApplication::PostRender()
{
    ImGui::Render();
    ImGui_ImplAllegro5_RenderDrawData(ImGui::GetDrawData());
    al_flip_display();
}

void AllegroApplication::Deinit()
{
    al_destroy_display(m_display);
    al_shutdown_image_addon();

    al_shutdown_primitives_addon();

	al_shutdown_font_addon();

    //al_shutdown_ttf_addon();

#ifdef AETHER_ENABLE_AUDIO
    al_uninstall_audio();
#endif

    al_uninstall_keyboard();
    al_uninstall_mouse();
}

void AllegroApplication::PreUpdate()
{
    ALLEGRO_EVENT ev;
    while( al_get_next_event(m_eventQueue, &ev) )
    {
        ImGui_ImplAllegro5_ProcessEvent(&ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            Close();
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
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_RESIZE)
        {
            ImGui_ImplAllegro5_InvalidateDeviceObjects();
            al_acknowledge_resize(m_display);
            ImGui_ImplAllegro5_CreateDeviceObjects();
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

void AllegroApplication::PostUpdate()
{
    _input_post_update();
}

void AllegroApplication::GrabMouse()
{
    assert(al_grab_mouse(m_display));
}

void AllegroApplication::UngrabMouse()
{
    assert(al_ungrab_mouse());
}

}
}
