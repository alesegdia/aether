#pragma once

#include <SDL.h>

#include <nether/nether.h>

#include "aether/graphics/gl/gl_rendermodule.h"

#include "../texture.h"

namespace aether::graphics
{

	class GLTexture : public Texture
	{
	public:
		GLTexture(GLRenderContext* owner)
			: Texture(owner)
		{

		}

		nether::Texture GetNetherTexture()
		{
			return m_tex;
		}

	private:
		nether::Texture m_tex;

	};

}
