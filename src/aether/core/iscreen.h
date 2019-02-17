#pragma once

#include <memory>

namespace aether {
namespace core {

class IScreen
{
public:
    typedef IScreen* Ptr;

    virtual ~IScreen() = 0 ;

    /**
     * @brief called every time the screen is put to active
     */
    virtual void show() = 0 ;

    /**
     * @brief called every time the screen is removed from current active
     */
    virtual void hide() = 0 ;

    /**
     * @brief for game logic
     * @param delta time between current and last frames
     */
    virtual void update(uint64_t delta) = 0 ;

    /**
     * @brief called in a fixed rate, for rendering
     */
    virtual void render() = 0 ;

};

}
}
