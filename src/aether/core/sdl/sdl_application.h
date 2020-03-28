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

    void grabMouse() final;


    // ApplicationBase interface
protected:
    int init(int argc, char **argv) final;

private:
    SDL_Window* m_display = NULL;
    SDL_Renderer* m_renderer = NULL;

    // ApplicationBase interface
protected:
    void cleanup();

    void preUpdate() final;

    void postUpdate() final;

    void preRender() final;

    void postRender() final;


};

typedef SDLApplication Application;


}
}
