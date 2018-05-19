#include "applicationbase.h"
#include "time.h"

namespace aether{
namespace core {

ApplicationBase::ApplicationBase( int screen_width, int screen_height )
    : m_screenHeight(screen_height),
      m_screenWidth(screen_width)
{

}

ApplicationBase::~ApplicationBase()
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
    uint64_t accum[2] = { 0, 0 };

    while( false == m_doExit )
    {
        now = get_time();
        uint64_t delta = now - then;

        accum[0] += delta;
        accum[1] += delta;

        then = now;

        // render
        if( accum[0] > m_renderFPS )
        {
            accum[0] -= m_renderFPS;
            preRender();
            render();
            postRender();
        }

        // update
        while( accum[1] > m_updateFPS )
        {
            accum[1] -= m_updateFPS;
            preUpdate();
            update(m_updateFPS);
            postUpdate();
        }
    }

    dispose();
    cleanup();

	return 0;
}

void ApplicationBase::setScreen(IScreen::Ptr screen)
{
    if( m_currentScreen != nullptr )
    {
        m_currentScreen->hide();
    }

    m_currentScreen = screen;
    m_currentScreen->show();
}

void ApplicationBase::setUpdateFPS(uint64_t fps)
{
    m_updateFPS = fps;
}

void ApplicationBase::setRenderFPS(uint64_t fps)
{
    m_renderFPS = fps;
}

int ApplicationBase::screenWidth()
{
    return m_screenWidth;
}

int ApplicationBase::screenHeight()
{
    return m_screenHeight;
}

void ApplicationBase::close()
{
    m_doExit = true;
}

int ApplicationBase::ready(int argc, char **argv)
{
    return 0;
}

void ApplicationBase::dispose()
{

}

}
}
