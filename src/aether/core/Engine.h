#pragma once

#include "aether/render/IRenderModule.h"
#include "aether/scene/scene.h"

namespace aether
{
	void init();

	class Engine
	{
	public:
		template <typename RendererType>
		void CreateRenderer()
		{
			assert(m_renderer == nullptr);
			m_renderer = new RendererType();
		}

		render::IRenderModule* GetRenderer()
		{
			return m_renderer;
		}


		void ResetScene()
		{
			m_scene = {};
		}

		void Cleanup()
		{
			delete m_renderer;
		}


	private:
		render::IRenderModule* m_renderer;
		scene::Scene m_scene;

	};


	Engine* get_engine();

}
