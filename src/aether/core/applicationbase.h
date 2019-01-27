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

    int exec(int argc, char** argv);

    void setScreen(IScreen::Ptr screen);

    void setUpdateFPS(uint64_t fps);
    void setRenderFPS(uint64_t fps);

    int screenWidth();

    int screenHeight();

    void close();

protected:

    /**
     * @brief init called before ready for implementatioon
     * specific initialization
     * @param argc
     * @param argv
     */
    virtual int init(int argc, char** argv) = 0;

    /**
     * @brief ready to be implemented in derived class
     * @param argc
     * @param argv
     */
    virtual int ready(int argc, char** argv);

    /**
     * @brief dispose called to clean user code
     */
    virtual void dispose();

    /**
     * @brief cleanup called to clean the implementation resources
     */
    virtual void cleanup() = 0 ;

    /**
     * @brief preUpdate executed BEFORE updating the screen
     */
    virtual void preUpdate() = 0 ;

    virtual void update(uint64_t delta)
    {
        if( m_currentScreen != nullptr )
        {
            m_currentScreen->update(delta);
        }
    }

    virtual void render()
    {
        if( m_currentScreen != nullptr )
        {
            m_currentScreen->render();
        }
    }

    virtual void preRender() = 0 ;
    virtual void postRender() = 0 ;

    /**
     * @brief postUpdate executed AFTER updating the screen
     */
    virtual void postUpdate() = 0 ;

	virtual void grabMouse() = 0 ;

private:
    void setFPS(uint64_t& timer, uint64_t fps)
    {
        timer = uint64_t(1e6) / fps;
    }

    int m_screenWidth;
    int m_screenHeight;

    bool m_doExit = false;

    uint64_t m_renderStepTimer = uint64_t(1e6) / 32;
    uint64_t m_updateStepTimer = uint64_t(1e6) / 64;

    IScreen::Ptr m_currentScreen = nullptr;

};

}
}

