#pragma once

namespace aether {
namespace core {

enum class KeyCode;

class IInputProcessor
{
public:

    typedef IInputProcessor* Ptr;

    virtual void onKeyUp(KeyCode key) = 0 ;
    virtual void onKeyDown(KeyCode key) = 0 ;

};


}
}
