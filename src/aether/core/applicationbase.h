#pragma once

#include "iscreen.h"
#include <stdint.h>
#include <vector>
#include "input.h"

namespace aether {
namespace core {

class CommandLineArguments
{
public:
    CommandLineArguments(int argc, char** argv)
    {
        for (int i = 0; i < argc; i++)
        {
            m_commandLineArguments.push_back(argv[i]);
        }
    }

    bool Find(const std::string& item) const
    {
        return std::find(m_commandLineArguments.begin(), m_commandLineArguments.end(), item) != m_commandLineArguments.end();
    }

private:
    std::vector<std::string> m_commandLineArguments;

};

class ApplicationBase
{
public:
    ApplicationBase( int screen_width, int screen_height );
    virtual ~ApplicationBase() = 0 ;

    int Exec(const CommandLineArguments& args);
	int Initialize(const CommandLineArguments& args);
	void Run();
	void Deinitialize();
	void SetScreen(std::shared_ptr<IScreen> screen);
	int GetApplicationWindowScreenWidth() const;
	int GetApplicationWindowScreenHeight() const;
	void Close();
    void Quit()
    {
        Close();
    }

    virtual std::vector<std::string> GetAssetPaths() const
    {
        return {};
    }

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
    virtual int Init(const CommandLineArguments& args) = 0;

    /**
     * @brief ready to be implemented in derived class
     * @param argc
     * @param argv
     */
    virtual int Ready(const CommandLineArguments& args);

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
    virtual void GameStep(uint64_t delta) {}
    virtual void GameRender() {}

    virtual void GrabMouse() = 0;
    virtual void UngrabMouse() = 0;

    virtual int AppImplementationInit(const CommandLineArguments& args) { return 0; }

    void Exit()
    {
        Close();
    }

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

