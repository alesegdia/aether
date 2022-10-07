#pragma once

#include <memory>
#include <deque>


namespace aether {
namespace core {

class IScreen
{
public:

    virtual ~IScreen() = 0 ;

    /**
     * @brief called every time the screen is put to active
     */
    virtual int Load() = 0 ;

    /**
     * @brief called every time the screen is removed from current active
     */
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

private:
    std::deque<std::shared_ptr<IScreen>> m_subScreens;
    bool m_updateOnParent = false;
    bool m_renderOnParent = false;

};

}
}
