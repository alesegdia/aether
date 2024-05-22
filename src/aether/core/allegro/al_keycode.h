#pragma once

#include <allegro5/allegro5.h>

#include <stdint.h>

namespace aether {

namespace core {


enum class KeyCode : int
{
    Up = ALLEGRO_KEY_UP,
    Down = ALLEGRO_KEY_DOWN,
    Left = ALLEGRO_KEY_LEFT,
    Right = ALLEGRO_KEY_RIGHT,
    Enter = ALLEGRO_KEY_ENTER,
    Escape = ALLEGRO_KEY_ESCAPE,
    Space = ALLEGRO_KEY_SPACE,
    Backspace = ALLEGRO_KEY_BACKSPACE,
    LShift = ALLEGRO_KEY_RSHIFT,
    RShift = ALLEGRO_KEY_LSHIFT,
    Fullstop = ALLEGRO_KEY_FULLSTOP,
    A = ALLEGRO_KEY_A,
    B = ALLEGRO_KEY_B,
    C = ALLEGRO_KEY_C,
    D = ALLEGRO_KEY_D,
    E = ALLEGRO_KEY_E,
    F = ALLEGRO_KEY_F,
    G = ALLEGRO_KEY_G,
    H = ALLEGRO_KEY_H,
    I = ALLEGRO_KEY_I,
    J = ALLEGRO_KEY_J,
    K = ALLEGRO_KEY_K,
    L = ALLEGRO_KEY_L,
    M = ALLEGRO_KEY_M,
    N = ALLEGRO_KEY_N,
    O = ALLEGRO_KEY_O,
    P = ALLEGRO_KEY_P,
    Q = ALLEGRO_KEY_Q,
    R = ALLEGRO_KEY_R,
    S = ALLEGRO_KEY_S,
    T = ALLEGRO_KEY_T,
    U = ALLEGRO_KEY_U,
    V = ALLEGRO_KEY_V,
    W = ALLEGRO_KEY_W,
    X = ALLEGRO_KEY_X,
    Y = ALLEGRO_KEY_Y,
    Z = ALLEGRO_KEY_Z,
    K0 = ALLEGRO_KEY_0,
    K1 = ALLEGRO_KEY_1,
    K2 = ALLEGRO_KEY_2,
    K3 = ALLEGRO_KEY_3,
    K4 = ALLEGRO_KEY_4,
    K5 = ALLEGRO_KEY_5,
    K6 = ALLEGRO_KEY_6,
    K7 = ALLEGRO_KEY_7,
    K8 = ALLEGRO_KEY_8,
    K9 = ALLEGRO_KEY_9,

    F1  = ALLEGRO_KEY_F1,
    F2  = ALLEGRO_KEY_F2,
    F3  = ALLEGRO_KEY_F3,
    F4  = ALLEGRO_KEY_F4,
    F5  = ALLEGRO_KEY_F5,
    F6  = ALLEGRO_KEY_F6,
    F7  = ALLEGRO_KEY_F7,
    F8  = ALLEGRO_KEY_F8,
    F9  = ALLEGRO_KEY_F9,
    F10 = ALLEGRO_KEY_F10,
    F11 = ALLEGRO_KEY_F11,
    F12 = ALLEGRO_KEY_F12,

    NumKeys = ALLEGRO_KEY_MAX
};

enum class MouseButton : int
{
    Left = 1,
    Right = 2,
    Middle = 4
};


}

}

