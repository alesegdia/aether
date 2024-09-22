#pragma once

#include "aether/core/ModuleObject.h"
#include "aether/math/vec.h"


namespace aether::render {

    class IRenderModule;

    class Texture : public core::ModuleObject
    {
    protected:
        Texture(ModuleObject* o) : ModuleObject(o) {}

    public:
        IRenderModule* GetRenderer() const;

        virtual math::Vec2i GetSize() const = 0;

    };

}
