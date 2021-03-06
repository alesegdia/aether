#pragma once

#include "../applicationbase.h"

#include "../input.h"

namespace aether {
namespace core {


class AllegroApplication : public ApplicationBase
{
public:
    AllegroApplication(int sw, int sh);
    virtual ~AllegroApplication()
    {

    }

    void grabMouse() final;


    // ApplicationBase interface
protected:
    int init(int argc, char **argv) final;

private:
    ALLEGRO_DISPLAY* m_display = NULL;
    ALLEGRO_EVENT_QUEUE* m_eventQueue = NULL;

    // ApplicationBase interface
protected:
    void cleanup();

    void preUpdate() final;

    void postUpdate() final;

    void preRender() final;

    void postRender() final;


};

typedef AllegroApplication Application;


}
}
