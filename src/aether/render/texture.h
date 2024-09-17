#pragma once

#include "aether/core/ModuleObject.h"
#include "../core/handle.h"
#include "../math/rect.h"

#include "aether/render/Color.h"

namespace aether::render {

    class IRenderModule;

    class Texture : public core::ModuleObject
    {
    protected:
        Texture(ModuleObject* o) : ModuleObject(o) {}

    public:
        IRenderModule* GetRenderer() const;

        math::Vec2i GetSize() const;

    };

}
