#include "aether/core/Engine.h"

#include "aether/render/IRenderModule.h"

#include "aether/scene/scene.h"

#include "aether/map/tilemap.h"
#include "aether/scene/ITilemapNode.h"
#include "aether/scene/ITextNode.h"

#include "aether/render/Font.h"
#include "aether/core/logger.h"

namespace {
	aether::Engine s_engine;
}

namespace aether
{
    void init_engine()
    {
        GEngine = &s_engine;
        s_engine.Init();
    }

	World::World()
	{
        m_scene = new scene::Scene();
	}

    World::~World()
    {
		delete m_scene;
    }

    scene::Scene& World::GetScene()
    {
        return *m_scene;
    }

    const scene::Scene& World::GetScene() const
    {
        return *m_scene;
    }

    void World::ResetScene()
    {
        m_scene = {};
    }

    void World::Step()
    {
        m_scene->Step();
    }

    void Engine::Init()
    {
        m_renderer = create_render_module();
        m_renderer->SetAssetsManager(m_assetsManager);
        m_assetsManager = new resources::AssetsManager();
		m_renderModuleAccessor = new render::RenderModuleAccessor();
        m_renderModuleAccessor->SetRenderModule(m_renderer);
        CreateWorld();
    }

    void Engine::SetDeltaTimeInMicroseconds(uint64_t deltaTimeInMicroseconds)
    {
        m_deltaTimeInMicroseconds = deltaTimeInMicroseconds;
    }

    void Engine::Cleanup()
    {
        delete m_renderModuleAccessor;
        delete m_renderer;
        delete m_currentWorld;
    }

    World* Engine::CreateWorld()
    {
        if (m_currentWorld != nullptr)
        {
            delete m_currentWorld;
        }
        m_currentWorld = new World();
        return m_currentWorld;
    }

    World* Engine::GetWorld()
    {
        return m_currentWorld;
    }

    uint64_t Engine::GetDeltaTimeInMicroseconds() const
    {
        return m_deltaTimeInMicroseconds;
    }

    render::Camera* Engine::CreateCamera(const glm::fvec2& viewport, render::ProjectionMode projectionMode)
    {
        return m_renderer->CreateCamera(viewport, projectionMode);
    }

    void Engine::SetActiveSceneCamera(render::Camera* camera)
    {
        m_renderer->SetActiveCamera(camera);
    }

    scene::ISpriteNode* Engine::CreateSpriteNode(const std::string& baseTexture)
    {
        auto texture = m_renderer->LoadTextureFromFile(baseTexture);

        auto txtsz = texture->GetSize();
        auto node = m_renderer->CreateSpriteNode({ txtsz.GetX(), txtsz.GetY() });
        node->SetTexture(texture);
        m_currentWorld->GetScene().AddToSceneRoot(node);
        return node;
    }

    scene::ISpriteNode* Engine::CreateSpriteNode(const glm::fvec2& size)
    {
        auto node = m_renderer->CreateSpriteNode(size);
        m_currentWorld->GetScene().AddToSceneRoot(node);
        return node;
    }

    scene::ITilemapNode* Engine::CreateTilemapNode(const std::string& tilemapPath)
    {
        Tmx::Map map;
        map.ParseFile(tilemapPath.c_str());
        if (map.HasError())
        {
            Logger::LogError("[" + std::to_string(map.GetErrorCode()) + "] " + map.GetErrorText());
            return nullptr;
        }

        auto aetherTilemap = std::make_shared<aether::tilemap::TileMap>(map);
        auto node = m_renderer->CreateTilemapNode(aetherTilemap);
        m_currentWorld->GetScene().AddToSceneRoot(node);
        return node;
    }

    scene::ITextNode* Engine::CreateTextNode()
	{
		auto node = m_renderer->CreateTextNode();
		m_currentWorld->GetScene().AddToSceneRoot(node);
		return node;
	}

	render::Font* Engine::CreateFont(const std::string& fontPath, int size)
	{
		return m_renderer->LoadFontFromFile(fontPath, size);
	}

    render::RenderModuleAccessor* Engine::GetRenderModuleAccessor()
    {
        return m_renderModuleAccessor;
    }

    resources::AssetsManager* Engine::GetAssetsManager()
    {
        return m_assetsManager;
    }

    Engine* GEngine = nullptr;
}