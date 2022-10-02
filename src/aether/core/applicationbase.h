#pragma once

#include "iscreen.h"
#include <stdint.h>
#include "input.h"

namespace aether {
namespace core {

class ApplicationBase
{
public:
    ApplicationBase( int screen_width, int screen_height );
    virtual ~ApplicationBase() = 0 ;

    int Exec(int argc, char** argv);
	int Initialize(int argc, char** argv);
	void Run();
	void Deinitialize();
	void SetScreen(std::shared_ptr<IScreen> screen);
	int GetApplicationWindowScreenWidth() const;
	int GetApplicationWindowScreenHeight() const;
	void Close();

private:
	void Step();

	void SetUpdateFPS(uint64_t fps);
	void SetRenderFPS(uint64_t fps);

protected:

    /**
     * @brief init called before ready for implementatioon
     * specific initialization
     * @param argc
     * @param argv
     */
    virtual int Init(int argc, char** argv) = 0;

    /**
     * @brief ready to be implemented in derived class
     * @param argc
     * @param argv
     */
    virtual int Ready(int argc, char** argv);

    /**
     * @brief dispose called to clean user code
     */
    virtual void Dispose();

    /**
     * @brief cleanup called to clean the implementation resources
     */
    virtual void Deinit() = 0 ;

    /**
     * @brief preUpdate executed BEFORE updating the screen
     */
    virtual void PreUpdate() = 0 ;

    virtual void Update(uint64_t delta);

    virtual void Render();

    virtual void PreRender() = 0 ;
    virtual void PostRender() = 0 ;

    /**
     * @brief postUpdate executed AFTER updating the screen
     */
    virtual void PostUpdate() = 0 ;

    virtual void GrabMouse() = 0 ;

private:
    void SetFPS(uint64_t& timer, uint64_t fps);

    int m_screenWidth;
    int m_screenHeight;
    uint64_t now, then;
    uint64_t accum[2] = { 0, 0 };

    bool m_doExit = false;

    uint64_t m_renderStepTimer = ((uint64_t)1e6) / 32;
    uint64_t m_updateStepTimer = ((int64_t)1e6) / 64;

    std::shared_ptr<IScreen> m_currentScreen = nullptr;

};

}
}

