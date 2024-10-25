#pragma once

#include "aether/render/IRenderModule.h"
#include "aether/scene/scene.h"

namespace aether
{
	void init_engine();
	aether::render::IRenderModule* create_render_module();
	scene::ISceneNodeFactory* get_node_factory();
	scene::Scene& get_scene();

	class World
	{
	public:
		~World() = default;

		scene::Scene& GetScene()
		{
			return m_scene;
		}

		const scene::Scene& GetScene() const
		{
			return m_scene;
		}

		void ResetScene()
		{
			m_scene = {};
		}

		void Step()
		{
			m_scene.Step();
		}

	private:
		scene::Scene m_scene;

	};

	class Engine
	{
	public:
		void Init()
		{
			m_renderer = create_render_module();
			m_renderModuleAccessor.SetRenderModule(m_renderer);
			CreateWorld();
		}

		void SetDeltaTimeInMicroseconds(uint64_t deltaTimeInMicroseconds)
		{
			m_deltaTimeInMicroseconds = deltaTimeInMicroseconds;
		}

		void Cleanup()
		{
			delete m_renderer;
			delete m_currentWorld;
		}

		World* CreateWorld()
		{
			if (m_currentWorld != nullptr)
			{
				delete m_currentWorld;
			}
			m_currentWorld = new World();
			return m_currentWorld;
		}

		World* GetWorld()
		{
			return m_currentWorld;
		}

		uint64_t GetDeltaTimeInMicroseconds() const
		{
			return m_deltaTimeInMicroseconds;
		}

		scene::ISpriteNode* CreateSpriteNode(const std::string& baseTexture)
		{
			auto texture = m_renderer->LoadTextureFromFile(baseTexture);
			auto node = m_renderer->CreateSpriteNode();
			node->SetTexture(texture);
			m_currentWorld->GetScene().AddToSceneRoot(node);
			return node;
		}

		scene::ISpriteNode* CreateSpriteNode()
		{
			auto node = m_renderer->CreateSpriteNode();
			m_currentWorld->GetScene().AddToSceneRoot(node);
			return node;
		}

		render::RenderModuleAccessor* GetRenderModuleAccessor()
		{
			return &m_renderModuleAccessor;
		}

	private:
		render::RenderModuleAccessor m_renderModuleAccessor;
		render::IRenderModule* m_renderer;
		World* m_currentWorld;
		uint64_t m_deltaTimeInMicroseconds = 0;

	};

	extern class Engine* GEngine;

}
