#pragma once

#include "platform.h"

#include "audio/sample.h"
#include "audio/stream.h"

#include "core/time.h"
#include "core/resourcemanager.h"
#include "core/iscreen.h"
#include "core/textinputprocessor.h"

#include "render/color.h"
#include "render/font.h"
#include "render/render.h"
#include "render/spritesheet.h"
#include "render/texture.h"
#include "render/animation.h"
#include "render/asepriteanimloader.h"
#include "render/topdownscroller.h"

#include "render/camera.h"

#include "math/matrix.h"
#include "math/vec.h"
#include "math/rect.h"
#include "math/rng.h"

#include "map/collisiontilemap.h"
#include "map/tilemap.h"

#include "scene/scene.h"
#include "scene/spritenode.h"
#include "scene/animationnode.h"
#include "scene/gridnode.h"

#include "rztl/rztl.h"

#include "json11.hpp"


namespace aether
{
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
}
