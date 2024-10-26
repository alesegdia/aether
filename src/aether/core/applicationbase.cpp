#include "applicationbase.h"

#include <utility>
#include <iostream>
#include "aether/core/logger.h"
#include "aether/core/Engine.h"

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

int ApplicationBase::Initialize(const CommandLineArguments& args)
{
    Logger::LogMsg("Initializing Application.");
    int init_retcode = Init(args);

    if (init_retcode != 0) {
        Logger::LogError("Application implementation failed to initialize with code <retcode>. Exiting.");
        return init_retcode;
    }
    else
    {
        Logger::LogMsg("Application initialized successfully.");
    }

    aether::GEngine->GetRenderModuleAccessor()->Init();

    auto firstCam = aether::GEngine->CreateCamera({ GetApplicationWindowScreenWidth(), GetApplicationWindowScreenHeight() }, render::ProjectionMode::Orthographic );
	aether::GEngine->GetRenderModuleAccessor()->SetActiveCamera(firstCam);

    Logger::LogMsg("Custom app init.");
	int ready_retcode = Ready(args);
	if (ready_retcode != 0)
	{
        Logger::LogError("Custom app init implementation failed to initialize with code <retcode>. Exiting.");
		return ready_retcode;
	}

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

int ApplicationBase::Exec(const CommandLineArguments& args)
{
    AppImplementationInit(args);

	aether::init_engine();

    Initialize(args);


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
        aether::GEngine->GetRenderModuleAccessor()->Render();
        // Render();
        PostRender();
    }

    // update
    while (accum[1] > m_updateStepTimer)
    {
        accum[1] -= m_updateStepTimer;
        PreUpdate();
        aether::GEngine->GetWorld()->Step();
        Update(m_updateStepTimer);
        PostUpdate();
        if (m_currentScreen != nullptr)
        {
            if (m_currentScreen->HasRequestedCloseApp())
            {
                Close();
            }
            auto nextScreen = m_currentScreen->PopNextScreen();
            if (nextScreen != nullptr)
            {
                SetScreen(nextScreen);
            }
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

int ApplicationBase::Ready(const CommandLineArguments& args)
{
    return 0;
}

void ApplicationBase::Dispose()
{

}

void ApplicationBase::Update(uint64_t delta)
{
    GameStep(delta);
	if (m_currentScreen != nullptr)
	{
		m_currentScreen->UpdateWithSubscreen(delta);
	}
}

void ApplicationBase::Render()
{
    GameRender();
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
