#pragma once

#include <cstdint>

#ifdef AETHER_USE_ALLEGRO
#include "allegro/keycode.h"
#elif AETHER_USE_VITA
#include "vita/keycode.h"
#endif

#include "iinputprocessor.h"

namespace aether {
namespace core {

struct MouseState {
    int x;
    int y;
    uint8_t buttons;
};

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
