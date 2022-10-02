#pragma once

#include "../applicationbase.h"
#include "SDL.h"

#include "../input.h"

namespace aether {
namespace core {


class SDLApplication : public ApplicationBase
{
public:
    SDLApplication(int sw, int sh);
    virtual ~SDLApplication()
    {

    }

    void GrabMouse() final;


    // ApplicationBase interface
protected:
    int AppImplementationInit(int argc, char **argv) final;

private:
    SDL_Window* m_display = NULL;
    SDL_Renderer* m_renderer = NULL;

    // ApplicationBase interface
protected:
    void Deinit();

    void PreUpdate() final;

    void PostUpdate() final;

    void PreRender() final;

    void PostRender() final;


};

typedef SDLApplication Application;


}
}
