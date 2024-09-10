#pragma once

#include <SDL.h>

#include <stdint.h>

namespace aether {

namespace core {


enum class KeyCode : int
{
    Up = SDL_SCANCODE_UP,
    Down = SDL_SCANCODE_DOWN,
    Left = SDL_SCANCODE_LEFT,
    Right = SDL_SCANCODE_RIGHT,
    Enter = SDL_SCANCODE_RETURN,
    Escape = SDL_SCANCODE_ESCAPE,
    Space = SDL_SCANCODE_SPACE,
    Fullstop = SDL_SCANCODE_PERIOD,
    Backspace = SDL_SCANCODE_BACKSPACE,
    RShift = SDL_SCANCODE_RSHIFT,
    LShift = SDL_SCANCODE_LSHIFT,
    A = SDL_SCANCODE_A,
    B = SDL_SCANCODE_B,
    C = SDL_SCANCODE_C,
    D = SDL_SCANCODE_D,
    E = SDL_SCANCODE_E,
    F = SDL_SCANCODE_F,
    G = SDL_SCANCODE_G,
    H = SDL_SCANCODE_H,
    I = SDL_SCANCODE_I,
    J = SDL_SCANCODE_J,
    K = SDL_SCANCODE_K,
    L = SDL_SCANCODE_L,
    M = SDL_SCANCODE_M,
    N = SDL_SCANCODE_N,
    O = SDL_SCANCODE_O,
    P = SDL_SCANCODE_P,
    Q = SDL_SCANCODE_Q,
    R = SDL_SCANCODE_R,
    S = SDL_SCANCODE_S,
    T = SDL_SCANCODE_T,
    U = SDL_SCANCODE_U,
    V = SDL_SCANCODE_V,
    W = SDL_SCANCODE_W,
    X = SDL_SCANCODE_X,
    Y = SDL_SCANCODE_Y,
    Z = SDL_SCANCODE_Z,
    K0 = SDL_SCANCODE_KP_0,
    K1 = SDL_SCANCODE_KP_1,
    K2 = SDL_SCANCODE_KP_2,
    K3 = SDL_SCANCODE_KP_3,
    K4 = SDL_SCANCODE_KP_4,
    K5 = SDL_SCANCODE_KP_5,
    K6 = SDL_SCANCODE_KP_6,
    K7 = SDL_SCANCODE_KP_7,
    K8 = SDL_SCANCODE_KP_8,
    K9 = SDL_SCANCODE_KP_9,
    NumKeys = SDL_NUM_SCANCODES
};

enum class MouseButton : Uint8
{
    Left = SDL_BUTTON_LEFT,
    Right = SDL_BUTTON_RIGHT,
    Middle = SDL_BUTTON_MIDDLE
};


}

}

