#pragma once

#include <glm/glm.hpp>
#include <string>
namespace aether::render
{
	class IRenderModule;
	class Camera;
	class RenderModuleAccessor;
	enum class ProjectionMode;
}

namespace aether::scene
{
	class Scene;
	class ISpriteNode;
    class ITilemapNode;
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
        void Init();
        void SetDeltaTimeInMicroseconds(uint64_t deltaTimeInMicroseconds);
        void Cleanup();
        World* CreateWorld();
        World* GetWorld();
        uint64_t GetDeltaTimeInMicroseconds() const;
        render::Camera* CreateCamera(const glm::fvec2& viewport, render::ProjectionMode projectionMode);
        void SetActiveSceneCamera(render::Camera* camera);
        scene::ISpriteNode* CreateSpriteNode(const std::string& baseTexture);
        scene::ISpriteNode* CreateSpriteNode(const glm::fvec2& size);
        scene::ITilemapNode* CreateTilemapNode(const std::string& tilemapPath);

        render::RenderModuleAccessor* GetRenderModuleAccessor();

    private:
        render::RenderModuleAccessor* m_renderModuleAccessor;
        render::IRenderModule* m_renderer;
        World* m_currentWorld;
        uint64_t m_deltaTimeInMicroseconds = 0;
    };

    extern Engine* GEngine;
}