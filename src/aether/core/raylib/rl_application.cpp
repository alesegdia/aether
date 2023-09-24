#include "rl_application.h"

#include "raylib.h"
#include "GLFW/glfw3.h"

namespace aether {
namespace core {

RaylibApplication::RaylibApplication(int sw, int sh)
    : ApplicationBase(sw, sh)
{

}

RaylibApplication::~RaylibApplication()
{

}

int RaylibApplication::Init(int argc, char **argv)
{
    InitWindow(GetApplicationWindowScreenWidth(), GetApplicationWindowScreenHeight(), "");
    GLFWwindow* window = static_cast<GLFWwindow*>(GetGlfwWindowHandle());
    //glfwSetKey
    return 0;
}

void RaylibApplication::PreRender()
{
    BeginDrawing();
}

void RaylibApplication::PostRender()
{
	EndDrawing();
	SwapScreenBuffer();
}

void RaylibApplication::Deinit()
{
    CloseWindow();
}

void RaylibApplication::PreUpdate()
{
	PollInputEvents();

}

void RaylibApplication::PostUpdate()
{
    _input_post_update();
}

void RaylibApplication::GrabMouse()
{

}

}
}
