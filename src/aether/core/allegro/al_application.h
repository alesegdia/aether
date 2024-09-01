#pragma once

#include "../applicationbase.h"

#include "../input.h"

namespace aether {
namespace core {


class AllegroApplication : public ApplicationBase
{
public:
    AllegroApplication(int sw, int sh);
    virtual ~AllegroApplication();

    void GrabMouse() final;
    void UngrabMouse() final;

protected:
    int Init(const CommandLineArguments& args) final;

private:
    ALLEGRO_DISPLAY* m_display = NULL;
    ALLEGRO_EVENT_QUEUE* m_eventQueue = NULL;

protected:
    void Deinit() final;
    void PreUpdate() final;
    void PostUpdate() final;
    void PreRender() final;
    void PostRender() final;


};

typedef AllegroApplication Application;


}
}
