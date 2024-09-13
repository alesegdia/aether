#pragma once


#include "aether/graphics/texture.h"

#include <memory>


#include "aether/core/ModuleObject.h"

namespace aether::graphics
{

    class IRenderModule : public core::ModuleObject
    {
    protected:
        IRenderModule(ModuleObject* o) : ModuleObject(o) {}

    public:
        virtual std::shared_ptr<Texture> LoadTexture(const std::string& path) = 0;
    };


}