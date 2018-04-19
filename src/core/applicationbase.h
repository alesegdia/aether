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

    void setScreen(IScreen::Ptr screen)
    {
        if( m_currentScreen != nullptr )
        {
            m_currentScreen->hide();
        }

        m_currentScreen = screen;
        m_currentScreen->show();
    }

    void setUpdateFPS(uint64_t fps);
    void setRenderFPS(uint64_t fps);

    void close();

protected:

    /**
     * @brief init called before ready for implementatioon
     * specific initialization
     * @param argc
     * @param argv
     */
    virtual void init(int argc, char** argv) = 0;

    /**
     * @brief ready to be implemented in derived class
     * @param argc
     * @param argv
     */
    virtual void ready(int argc, char** argv) = 0 ;

    /**
     * @brief dispose called to clean user code
     */
    virtual void dispose() = 0 ;

    /**
     * @brief cleanup called to clean the implementation resources
     */
    virtual void cleanup() = 0 ;

    /**
     * @brief preUpdate executed BEFORE updating the screen
     */
    virtual void preUpdate() = 0 ;

    /**
     * @brief postUpdate executed AFTER updating the screen
     */
    virtual void postUpdate() = 0 ;


private:
    int m_screenWidth;
    int m_screenHeight;

    bool m_doExit = false;

    uint64_t m_renderFPS = 10e6 / 64;
    uint64_t m_updateFPS = 10e6 / 64;

    IScreen::Ptr m_currentScreen;

};

}
}

