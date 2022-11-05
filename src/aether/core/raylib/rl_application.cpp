#include "rl_application.h"

#include <iostream>

#include <imgui.h>
#include <imgui_impl_allegro5.h>

#include <iostream>

#include "raylib.h"

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
