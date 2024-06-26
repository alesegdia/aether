#pragma once

#include <memory>
#include <deque>


namespace aether {
namespace core {

class IScreen
{
public:

    virtual ~IScreen() = 0 ;

    /// <summary>
    /// Called everytime the screen is moved to active
    /// </summary>
    /// <returns>Zero if everything went fine, different than zero otherwise</returns>
    virtual int Load() = 0 ;

    /// <summary>
    /// Called everytime the screen is removed from active
    /// </summary>
    /// <returns></returns>
    virtual int Unload() = 0 ;

    bool UpdateInactive()
    {
        return m_updateOnParent;
    }

    bool RenderInactive()
    {
        return m_renderOnParent;
    }

    void UpdateWithSubscreen(uint64_t delta)
    {
        ApplyAction(&IScreen::UpdateInactive, &IScreen::Update, delta);
    }

    void RenderWithSubscreen()
    {
        ApplyAction(&IScreen::RenderInactive, &IScreen::Render);
    }

    template <typename... Args>
    void ApplyAction( bool (IScreen::*checkMethod) (void), void (IScreen::*applyMethod)(Args...), Args... args )
    {
        if( m_subScreens.size() > 0 )
        {
            if( (this->*checkMethod)() ) {
                (this->*applyMethod)(args...);
            }
            const auto& back = m_subScreens.back();
            for( const auto& subscreen : m_subScreens )
            {
                if( subscreen == back )
                {
                    ((*subscreen).*applyMethod)(args...);
                }
                else if(((*subscreen).*checkMethod)())
                {
                    ((*subscreen).*applyMethod)(args...);
                }
            }
        }
        else
        {
            (this->*applyMethod)(args...);
        }
    }

    bool HasRequestedCloseApp()
    {
	    return m_requestCloseApp;
    }

    std::shared_ptr<IScreen> PopNextScreen()
    {
	    auto tmp = m_nextScreen;
        m_nextScreen = nullptr;
        return tmp;
    }

protected:

    /**
     * @brief for game logic
     * @param delta time between current and last frames
     */
    virtual void Update(uint64_t delta) = 0 ;

    /**
     * @brief called in a fixed rate, for rendering
     */
    virtual void Render() = 0 ;

    void PushSubscreen(std::shared_ptr<IScreen> subscreen)
    {
        m_subScreens.push_back(subscreen);
    }

    std::shared_ptr<IScreen> PopSubscreen()
    {
        std::shared_ptr<IScreen> item = m_subScreens.back();
        m_subScreens.pop_back();
        return item;
    }

    void SetOnParentBehaviour(bool update, bool render)
    {
        m_updateOnParent = update;
        m_renderOnParent = render;
    }

    void RequestCloseApp()
    {
	    m_requestCloseApp = true;
    }

    void GoToScreen(std::shared_ptr<IScreen> nextScreen)
    {
	    m_nextScreen = nextScreen;
    }

private:
    std::deque<std::shared_ptr<IScreen>> m_subScreens;
    bool m_updateOnParent = false;
    bool m_renderOnParent = false;
    bool m_requestCloseApp = false;
    std::shared_ptr<IScreen> m_nextScreen = nullptr;

};

}
}
