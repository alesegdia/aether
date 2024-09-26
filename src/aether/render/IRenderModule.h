#pragma once

#include "aether/core/ModuleObject.h"
#include "aether/render/Texture.h"
#include "aether/render/Font.h"
#include "aether/render/Camera.h"

namespace aether::render
{

    class IRenderModule : public core::ModuleObject
    {
    protected:
        IRenderModule(ModuleObject* o) : ModuleObject(o) {}

    public:
        virtual Texture* LoadTextureFromFile(const std::string& path) = 0;
        virtual Font* LoadFontFromFile(const std::string& path) = 0;
        virtual Camera* CreateCamera(const math::Vec2f& viewport) = 0;
        virtual math::Vec2i GetTextureSize(const Texture* tex) = 0;

    };

    class IPrimitiveDrawInterface
    {
    public:
        ~IPrimitiveDrawInterface() {}


        virtual void DrawSprite(Texture texture, int uv, int uy, int x, int y, int rotation) = 0;
    };

}

