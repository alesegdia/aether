#pragma once

namespace aether {
namespace core {

enum class KeyCode;

class IInputProcessor
{
public:

    typedef IInputProcessor* Ptr;

    virtual void OnKeyUp(KeyCode key) = 0 ;
    virtual void OnKeyDown(KeyCode key) = 0 ;

};


}
}
