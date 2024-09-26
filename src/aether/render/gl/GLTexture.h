#pragma once

#include <nether/nether.h>

#include "aether/render/texture.h"
#include "aether/render/IRenderModule.h"


namespace aether::render
{

	class GLTexture : public Texture
	{
	public:
		GLTexture(IRenderModule* owner, std::shared_ptr<nether::Texture> tex);
		math::Vec2i GetSize() const override;

		std::shared_ptr<nether::Texture> GetNetherTexture()
		{
			return m_texture;
		}

	private:
		std::shared_ptr<nether::Texture> m_texture;
	
	};

}
