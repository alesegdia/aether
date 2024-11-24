#pragma once

#include <glm/glm.hpp>
#include <string>
#include "aether/resources/AssetsManager.h"

namespace aether::render
{
	class IRenderModule;
	class Camera;
	class RenderModuleAccessor;
	enum class ProjectionMode;
	class Font;
}

namespace aether::scene
{
	class Scene;
	class ISpriteNode;
    class ITilemapNode;
    class ITextNode;
}

namespace aether
{
    aether::render::IRenderModule* create_render_module();
    void init_engine();

    class World
    {
    public:
        World();
        ~World();

        scene::Scene& GetScene();
        const scene::Scene& GetScene() const;
        void ResetScene();
        void Step();

    private:
        scene::Scene* m_scene;
    };

    class Engine
    {
    public:
        // Engine lifecycle
        void Init();
        void Cleanup();

		// Delta time management
        void SetDeltaTimeInMicroseconds(uint64_t deltaTimeInMicroseconds);
        uint64_t GetDeltaTimeInMicroseconds() const;

        // World management
        World* CreateWorld();
        World* GetWorld();
        void SetActiveSceneCamera(render::Camera* camera);

        // Entity creation helpers
        render::Camera* CreateCamera(const glm::fvec2& viewport, render::ProjectionMode projectionMode);
        scene::ISpriteNode* CreateSpriteNode(const std::string& baseTexture);
        scene::ISpriteNode* CreateSpriteNode(const glm::fvec2& size);
        scene::ITilemapNode* CreateTilemapNode(const std::string& tilemapPath);
        scene::ITextNode* CreateTextNode();
        render::Font* CreateFont(const std::string& fontPath, int size = 48);

        // Render module accessor
        render::RenderModuleAccessor* GetRenderModuleAccessor();
		resources::AssetsManager* GetAssetsManager();

    private:
        render::RenderModuleAccessor* m_renderModuleAccessor;
        render::IRenderModule* m_renderer;
        resources::AssetsManager* m_assetsManager;
        World* m_currentWorld;
        uint64_t m_deltaTimeInMicroseconds = 0;
    };

    extern Engine* GEngine;
}