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
        virtual Texture* CreateTexture() = 0;

        virtual int LoadTextureFromFile(const Texture* tex, const std::string& path) = 0;
        virtual math::Vec2i GetTextureSize(const Texture* tex) = 0;

        virtual void AddToBatch(const SceneNode* node)
        
    };

    class IPrimitiveDrawInterface
    {
    public:
        ~IPrimitiveDrawInterface() {}


        virtual void DrawSprite(Texture texture, int uv, int uy, int x, int y, int rotation) = 0;
    };

}

