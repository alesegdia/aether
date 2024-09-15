#pragma once

#include "aether/core/ModuleObject.h"

#include "aether/render/texture.h"

namespace aether::render
{

    class IRenderModule : public core::ModuleObject
    {
    protected:
        IRenderModule(ModuleObject* o) : ModuleObject(o) {}

    public:
        virtual std::shared_ptr<Texture> LoadTextureFromFile(const std::string& path) = 0;
    };

}

