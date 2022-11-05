#pragma once

#include <cstdint>

#ifdef AETHER_USE_ALLEGRO
#include "allegro/al_keycode.h"
#elif AETHER_USE_SDL
#include "sdl/sdl_keycode.h"
#elif AETHER_USE_3DS
#include "3ds/3ds_keycode.h"
#elif AETHER_USE_RAYLIB
#include "raylib/rl_keycode.h"
#endif

#include "iinputprocessor.h"


namespace aether {
namespace core {

struct MouseState {
    int x;
    int y;
    uint32_t buttons;
};

void enable_grab_mouse();

bool is_key_down(KeyCode key);
bool is_key_just_pressed(KeyCode key);

bool is_mouse_button_pressed(int button);
bool is_mouse_button_just_pressed(int button);

void _init_input();
void _notify_key_down(KeyCode key);
void _notify_key_up(KeyCode key);
void _notify_mouse_button_down(MouseButton button);

void _input_post_update();

MouseState& _get_mouse_state();

void add_input_processor(IInputProcessor::Ptr input_processor);
void remove_input_processor(IInputProcessor::Ptr input_processor);


}
}
