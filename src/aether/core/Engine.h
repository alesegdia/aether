#pragma once

#include "aether/render/IRenderModule.h"
#include "aether/scene/scene.h"

namespace aether
{
	void init_engine();
	render::IRenderModule* create_render_module();
	scene::Scene& get_scene();

	class World
	{
	public:
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

	private:
		scene::Scene m_scene;

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
			CreateWorld();
			m_renderer = create_render_module();
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


	Engine* get_engine();

}
