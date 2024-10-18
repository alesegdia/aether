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
		~World()
		{
			if (m_scene != nullptr)
			{
				delete m_scene;
			}
		}

		scene::Scene& GetScene()
		{
			assert(m_scene != nullptr);
			return *m_scene;
		}

		const scene::Scene& GetScene() const
		{
			assert(m_scene != nullptr);
			return *m_scene;
		}

		void ResetScene(scene::ISceneNodeFactory* nodeFactory)
		{
			if (m_scene != nullptr)
			{
				delete m_scene;
			}

			m_scene = new scene::Scene(nodeFactory);
		}

	private:
		scene::Scene* m_scene;

	};

	class Engine
	{
	public:
		render::IRenderModule* GetRenderer()
		{
			return m_renderer;
		}

		void Init()
		{
			m_renderer = create_render_module();
			CreateWorld();
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

	private:
		render::IRenderModule* m_renderer;
		World* m_currentWorld;

	};

	extern class Engine* GEngine;

}
