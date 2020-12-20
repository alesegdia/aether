#include "applicationbase.h"

#include <utility>
#include "time.h"

namespace aether{
namespace core {

ApplicationBase::ApplicationBase( int screen_width, int screen_height )
    : m_screenWidth(screen_width),
      m_screenHeight(screen_height)
{

}

ApplicationBase::~ApplicationBase()
= default;

int ApplicationBase::initialize(int argc, char** argv)
{
    int init_retcode = init(argc, argv);
    if (init_retcode != 0) {
        return init_retcode;
    }

    int ready_retcode = ready(argc, argv);
    if (ready_retcode != 0)
    {
        return ready_retcode;
    }

    _init_input();

    now = then = get_time();
    return 0;
}

void ApplicationBase::run()
{
    while (false == m_doExit)
    {
        step();
    }
}

int ApplicationBase::exec(int argc, char **argv)
{
    initialize(argc, argv);

    while( false == m_doExit )
    {
        step();
    }

    deinitialize();

	return 0;
}

void ApplicationBase::deinitialize()
{
    // this smells, check games and remove one of them
    dispose();
    cleanup();
}

void ApplicationBase::step()
{
    now = get_time();
    uint64_t delta = now - then;

    accum[0] += delta;
    accum[1] += delta;

    then = now;

    // render
    if (accum[0] > m_renderStepTimer)
    {
        accum[0] -= m_renderStepTimer;
        preRender();
        render();
        postRender();
    }

    // update
    while (accum[1] > m_updateStepTimer)
    {
        accum[1] -= m_updateStepTimer;
        preUpdate();
        update(m_updateStepTimer);
        postUpdate();
    }
}

void ApplicationBase::setScreen(std::shared_ptr<IScreen> screen)
{
    if( m_currentScreen != nullptr )
    {
        m_currentScreen->hide();
    }

    m_currentScreen = std::move(screen);
    m_currentScreen->show();
}

void ApplicationBase::setUpdateFPS(uint64_t fps)
{
    setFPS(m_updateStepTimer, fps);
;
}

void ApplicationBase::setRenderFPS(uint64_t fps)
{
    setFPS(m_renderStepTimer, fps);
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
