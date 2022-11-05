#pragma once

#include "../applicationbase.h"

#include "../input.h"

namespace aether {
namespace core {


class RaylibApplication : public ApplicationBase
{
public:
    RaylibApplication(int sw, int sh);
    virtual ~RaylibApplication();

    void GrabMouse() final;

protected:
    int Init(int argc, char **argv) final;

    void Deinit() final;
    void PreUpdate() final;
    void PostUpdate() final;
    void PreRender() final;
    void PostRender() final;

};

typedef RaylibApplication Application;


}
}
