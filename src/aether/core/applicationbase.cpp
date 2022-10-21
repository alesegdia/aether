#include "applicationbase.h"

#include <utility>
#include <iostream>
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

int ApplicationBase::Initialize(int argc, char** argv)
{
    int init_retcode = Init(argc, argv);
    if (init_retcode != 0) {
        return init_retcode;
    }

	int ready_retcode = Ready(argc, argv);
	if (ready_retcode != 0)
	{
		return ready_retcode;
	}

    std::cout << "ARGUMENTS: " << argc << std::endl;

    _init_input();

    now = then = get_time();
    return 0;
}

void ApplicationBase::Run()
{
    while (false == m_doExit)
    {
        Step();
    }
}

int ApplicationBase::Exec(int argc, char **argv)
{
    Initialize(argc, argv);

    while( false == m_doExit )
    {
        Step();
    }

    Deinitialize();

	return 0;
}

void ApplicationBase::Deinitialize()
{
    // this smells, check games and remove one of them
    Dispose();
    Deinit();
}

void ApplicationBase::Step()
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
        PreRender();
        Render();
        PostRender();
    }

    // update
    while (accum[1] > m_updateStepTimer)
    {
        accum[1] -= m_updateStepTimer;
        PreUpdate();
        Update(m_updateStepTimer);
        PostUpdate();
        if(m_currentScreen->HasRequestedCloseApp())
        {
	        Close();
        }
    }
}

void ApplicationBase::SetScreen(std::shared_ptr<IScreen> screen)
{
    int unloadReturnValue = 0;
    if( m_currentScreen != nullptr )
    {
        unloadReturnValue = m_currentScreen->Unload();
    }

	if (unloadReturnValue != 0)
	{
		std::cout << "There was a problem unloading a screen. Exiting the application.";
		Close();
	}
	else
	{
		m_currentScreen = std::move(screen);
		auto returnValue = m_currentScreen->Load();
		if (returnValue != 0)
		{
			std::cout << "There was a problem loading a screen. Exiting the application.";
			Close();
		}
	}
}

void ApplicationBase::SetUpdateFPS(uint64_t fps)
{
    SetFPS(m_updateStepTimer, fps);
}

void ApplicationBase::SetRenderFPS(uint64_t fps)
{
    SetFPS(m_renderStepTimer, fps);
}

int ApplicationBase::GetApplicationWindowScreenWidth() const
{
    return m_screenWidth;
}

int ApplicationBase::GetApplicationWindowScreenHeight() const
{
    return m_screenHeight;
}

void ApplicationBase::Close()
{
    m_doExit = true;
}

int ApplicationBase::Ready(int argc, char **argv)
{
    return 0;
}

void ApplicationBase::Dispose()
{

}

void ApplicationBase::Update(uint64_t delta)
{
	if (m_currentScreen != nullptr)
	{
		m_currentScreen->UpdateWithSubscreen(delta);
	}
}

void ApplicationBase::Render()
{
	if (m_currentScreen != nullptr)
	{
		m_currentScreen->RenderWithSubscreen();
	}
}

void ApplicationBase::SetFPS(uint64_t& timer, uint64_t fps)
{
	timer = ((uint64_t)1e6) / fps;
}

}
}
