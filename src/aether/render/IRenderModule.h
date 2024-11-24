#pragma once

#include "aether/scene/SceneNodeFactory.h"
#include "aether/core/ModuleObject.h"
#include "aether/math/vec.h"
#include "aether/math/rect.h"
#include <glm/glm.hpp>
#include "aether/scene/spritenode.h"
#include "aether/scene/ITilemapNode.h"
#include "aether/scene/ITextNode.h"
#include "aether/render/IBatchedEntity.h"
#include <string>

#include "aether/render/Camera.h"

#include "aether/resources/AssetsManager.h"

#include "Tmx.h"

namespace aether::tilemap
{
    class TileMap;
}


namespace aether::render
{

    class Font;
    class Texture;
    class ShaderProgram;
    class Sprite;

    /**
     * @brief Interface for the render module.
     *
     * This class provides an interface for rendering operations, including loading textures, fonts, shaders, and creating cameras and sprites.
     */
    class IRenderModule : public core::ModuleObject
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

        void SetClearColor(const glm::vec4& color)
        {
            m_clearColor = color;
        }

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
        virtual Camera* CreateCamera(const glm::fvec2& viewport, ProjectionMode projectionMode) = 0;

        /**
         * @brief Create a sprite.
         *
         * @param texture Pointer to the texture for the sprite.
         * @param rect The rectangle defining the sprite's dimensions.
         * @return Pointer to the created Sprite object.
         */
        virtual Sprite* CreateSprite(Texture* texture, const math::Recti& rect) = 0;


		virtual scene::ISpriteNode* CreateSpriteNode(const glm::fvec2& size) = 0;

        virtual scene::ITilemapNode* CreateTilemapNode(const std::shared_ptr<tilemap::TileMap>& map) = 0;

        virtual scene::ITextNode* CreateTextNode() = 0;

        virtual void Render() = 0;

        virtual void Init() = 0;

        void SetActiveCamera(Camera* newActiveCamera)
        {
            m_activeCamera = newActiveCamera;
        }

        Camera* GetActiveCamera() const
        {
            return m_activeCamera;
        }

        virtual void Refresh(IBatchedEntity* entity) = 0;

		void SetAssetsManager(resources::AssetsManager* assetsManager)
		{
			m_assetsManager = assetsManager;
		}

    protected:
		glm::vec4 GetClearColor() const
		{
			return m_clearColor;
		}

    private:

        glm::vec4 m_clearColor = { 1.f, 0.f, 1.f, 1.f };
        render::Camera* m_activeCamera;
		resources::AssetsManager* m_assetsManager;

    };


    class RenderModuleAccessor
    {
    public:
        RenderModuleAccessor() {}

        ~RenderModuleAccessor() = default;

		void SetRenderModule(IRenderModule* renderModule)
		{
			m_renderModule = renderModule;
		}

        void SetClearColor(const glm::vec4& color)
        {
            m_renderModule->SetClearColor(color);
        }

        Texture* LoadTextureFromFile(const std::string& path)
        {
            return m_renderModule->LoadTextureFromFile(path);
        }

		void Init()
		{
			m_renderModule->Init();
		}

        void Render()
		{
			m_renderModule->Render();
		}

		void SetActiveCamera(Camera* camera)
		{
			m_renderModule->SetActiveCamera(camera);
		}

		Camera* GetActiveCamera() const
		{
			return m_renderModule->GetActiveCamera();
		}

    private:
        IRenderModule* m_renderModule = nullptr;

    };

}