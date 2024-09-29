#pragma once

#include "aether/core/ModuleObject.h"

namespace aether::render
{

	class Font;
	class Texture;
	class ShaderProgram;
	class Sprite;
	class Camera;

    class IRenderModule : public core::ModuleObject
    {
    protected:
        IRenderModule(ModuleObject* o) : ModuleObject(o) {}

    public:
        virtual Texture* LoadTextureFromFile(const std::string& path) = 0;
		virtual Font* LoadFontFromFile(const std::string& path) = 0;
		virtual ShaderProgram* LoadShaderFromFile(const std::string& vspath, const std::string& fspath) = 0;
		virtual Camera* CreateCamera(const math::Vec2f& viewport) = 0;
		virtual Sprite* CreateSprite(Texture* texture, const math::Recti& rect) = 0;

    };





}

