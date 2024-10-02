#pragma once

#include "aether/scene/SceneNodeFactory.h"
#include "aether/core/ModuleObject.h"
#include "aether/math/vec.h"
#include "aether/math/rect.h"
#include <string>

namespace aether::render
{

    class Font;
    class Texture;
    class ShaderProgram;
    class Sprite;
    class Camera;

    /**
     * @brief Interface for the render module.
     *
     * This class provides an interface for rendering operations, including loading textures, fonts, shaders, and creating cameras and sprites.
     */
    class IRenderModule : public core::ModuleObject, public scene::ISceneNodeFactory
    {
    protected:
        /**
         * @brief Protected constructor to ensure the class is abstract.
         *
         * @param o Pointer to the parent ModuleObject.
         */
        IRenderModule(ModuleObject* o) : ModuleObject(o) {}

    public:
        virtual ~IRenderModule() = default;

        /**
         * @brief Load a texture from a file.
         *
         * @param path The file path to the texture.
         * @return Pointer to the loaded Texture object.
         */
        virtual Texture* LoadTextureFromFile(const std::string& path) = 0;

        /**
         * @brief Load a font from a file.
         *
         * @param path The file path to the font.
         * @param size The size of the font.
         * @return Pointer to the loaded Font object.
         */
        virtual Font* LoadFontFromFile(const std::string& path, int size) = 0;

        /**
         * @brief Load a shader program from files.
         *
         * @param vspath The file path to the vertex shader.
         * @param fspath The file path to the fragment shader.
         * @return Pointer to the loaded ShaderProgram object.
         */
        virtual ShaderProgram* LoadShaderFromFile(const std::string& vspath, const std::string& fspath) = 0;

        /**
         * @brief Create a camera.
         *
         * @param viewport The viewport size for the camera.
         * @return Pointer to the created Camera object.
         */
        virtual Camera* CreateCamera(const math::Vec2f& viewport, float rotation) = 0;

        /**
         * @brief Create a sprite.
         *
         * @param texture Pointer to the texture for the sprite.
         * @param rect The rectangle defining the sprite's dimensions.
         * @return Pointer to the created Sprite object.
         */
        virtual Sprite* CreateSprite(Texture* texture, const math::Recti& rect) = 0;

    };

}