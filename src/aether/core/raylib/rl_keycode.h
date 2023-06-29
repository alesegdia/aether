#pragma once

#include <raylib.h>
#include <GLFW/glfw3.h>


namespace aether {

namespace core {


enum class KeyCode : int
{
    Up = GLFW_KEY_UP,
    Down = GLFW_KEY_DOWN,
    Left = GLFW_KEY_LEFT,
    Right = GLFW_KEY_RIGHT,
    Enter = GLFW_KEY_ENTER,
    Escape = GLFW_KEY_ESCAPE,
    Space = GLFW_KEY_SPACE,
    A = GLFW_KEY_A,
    B = GLFW_KEY_B,
    C = GLFW_KEY_C,
    D = GLFW_KEY_D,
    E = GLFW_KEY_E,
    F = GLFW_KEY_F,
    G = GLFW_KEY_G,
    H = GLFW_KEY_H,
    I = GLFW_KEY_I,
    J = GLFW_KEY_J,
    K = GLFW_KEY_K,
    L = GLFW_KEY_L,
    M = GLFW_KEY_M,
    N = GLFW_KEY_N,
    O = GLFW_KEY_O,
    P = GLFW_KEY_P,
    Q = GLFW_KEY_Q,
    R = GLFW_KEY_R,
    S = GLFW_KEY_S,
    T = GLFW_KEY_T,
    U = GLFW_KEY_U,
    V = GLFW_KEY_V,
    W = GLFW_KEY_W,
    X = GLFW_KEY_X,
    Y = GLFW_KEY_Y,
    Z = GLFW_KEY_Z,
    K0 = GLFW_KEY_0,
    K1 = GLFW_KEY_1,
    K2 = GLFW_KEY_2,
    K3 = GLFW_KEY_3,
    K4 = GLFW_KEY_4,
    K5 = GLFW_KEY_5,
    K6 = GLFW_KEY_6,
    K7 = GLFW_KEY_7,
    K8 = GLFW_KEY_8,
    K9 = GLFW_KEY_9,
    NumKeys = GLFW_KEY_LAST 
};

enum class MouseButton : int
{
    Left = GLFW_MOUSE_BUTTON_LEFT,
    Right = GLFW_MOUSE_BUTTON_RIGHT,
    Middle = GLFW_MOUSE_BUTTON_MIDDLE
};


}

}

