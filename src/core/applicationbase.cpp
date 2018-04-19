#include "applicationbase.h"
#include "time.h"

namespace aether{
namespace core {

ApplicationBase::ApplicationBase( int screen_width, int screen_height )
    : m_screenHeight(screen_height),
      m_screenWidth(screen_width)
{

}

int ApplicationBase::exec(int argc, char **argv)
{
    int init_retcode = init(argc, argv);
    if( init_retcode != 0 ) {
        return init_retcode;
    }

    int ready_retcode = ready(argc, argv);
    if( ready_retcode != 0 )
    {
        return ready_retcode;
    }

    _init_input();

    double now, then;
    now = then = get_time();
    uint64_t accum[2]={ 0, 0 };

    while( false == m_doExit )
    {
        now = al_get_time();
        uint64_t delta = now - then;

        accum[0] += delta;
        accum[1] += delta;

        then = now;

        // render
        if( accum[0] > m_renderFPS )
        {
            accum[0] -= m_renderFPS;
            this->render();
        }

        // update
        while( accum[1]> m_updateFPS )
        {
            accum[1] -= m_updateFPS;
            preUpdate();

            m_currentScreen->update(delta);
            postUpdate();
        }
    }

    dispose();
    cleanup();

}

void ApplicationBase::setUpdateFPS(uint64_t fps)
{
    m_updateFPS = fps;
}

void ApplicationBase::setRenderFPS(uint64_t fps)
{
    m_renderFPS = fps;
}

void ApplicationBase::close()
{
    m_doExit = true;
}

void ApplicationBase::render()
{
    m_currentScreen->render();
}

}
}
