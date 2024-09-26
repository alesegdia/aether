#pragma once

#include "aether/core/applicationbase.h"
#include "SDL.h"

#ifdef AETHER_USE_GL
#include "glad/gl.h"
#endif

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

    virtual void GrabMouse() final;
    virtual void UngrabMouse() final
    {

    }


protected:
    int Init(const CommandLineArguments& args) final;

private:
    SDL_Window* m_window = NULL;
    SDL_Renderer* m_renderer = NULL;
    SDL_GLContext glContext;

    bool IsOpenGLActivated()
    {
#ifdef AETHER_USE_GL
        return true;
#else
        return false;
#endif
    }

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
