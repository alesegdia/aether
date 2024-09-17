#pragma once

#include <SDL.h>

#include <nether/nether.h>

#include "aether/render/gl/GLRenderModule.h"

#include "aether/render/texture.h"

namespace aether::render
{

	class GLTexture : public Texture
	{
	public:
		GLTexture(GLRenderModule* owner)
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
