#include "../input.h"

#include <cassert>
#include <cstring>

namespace aether {
namespace core {

static KeyCode last_key_pressed;
static int last_mousebutton_pressed;
static MouseState mouse_state;
static bool key_states[(int)(KeyCode::NumKeys)];
static constexpr size_t MAX_PROCESSORS = 10;
static IInputProcessor::Ptr processors[MAX_PROCESSORS];
static int last_processor_index = -1;


bool is_key_down(KeyCode key)
{
    return key_states[(int)key];
}

bool is_key_just_pressed(KeyCode key)
{
    return key == last_key_pressed;
}

void _init_input()
{
    memset(key_states, 0, (int)(KeyCode::NumKeys) * sizeof(bool));
    memset(processors, 0, sizeof(IInputProcessor::Ptr) * MAX_PROCESSORS);
}

bool is_mouse_button_pressed(int button)
{
    assert(
        button == (int)MouseButton::Left   ||
        button == (int)MouseButton::Right  ||
        button == (int)MouseButton::Middle
    );
    return mouse_state.buttons & button;
}
bool is_mouse_button_just_pressed(int button)
{
    return (int)last_mousebutton_pressed == button;
}

#define AETHER_FOREACH_PROCESSOR for( int pidx = 0; pidx <= last_processor_index; pidx++ )

void _notify_key_down(KeyCode key)
{
    key_states[(int)key] = true;
    last_key_pressed = key;

    AETHER_FOREACH_PROCESSOR
    {
        processors[pidx]->onKeyDown(key);
    }
}

void _notify_key_up(KeyCode key)
{
    key_states[(int)key] = false;
    AETHER_FOREACH_PROCESSOR
    {
        processors[pidx]->onKeyUp(key);
    }
}

void _notify_mouse_button_down(MouseButton button)
{
    last_mousebutton_pressed = (int)button;
}

MouseState& _get_mouse_state()
{
    return mouse_state;
}

void _input_post_update()
{
    last_key_pressed = KeyCode::NumKeys;
    if( (int)last_mousebutton_pressed != 0 )
    {
        last_mousebutton_pressed = 0;
    }
}

void add_input_processor(IInputProcessor::Ptr input_processor)
{
    assert(last_processor_index + 1 < MAX_PROCESSORS);
    last_processor_index++;
    processors[last_processor_index] = input_processor;
}

void remove_input_processor(IInputProcessor::Ptr input_processor)
{
    int removed_processor_index = -1;
    for( int i = 0; i <= last_processor_index; i++ )
    {
        if( processors[i] == input_processor )
        {
            removed_processor_index = i;
            break;
        }
    }
    assert(removed_processor_index != -1 && "The processor is not in the list");
    processors[removed_processor_index] = processors[last_processor_index];
    last_processor_index--;
}


}
}
