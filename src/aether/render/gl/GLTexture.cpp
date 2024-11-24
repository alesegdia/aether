#include "GLTexture.h"

namespace aether::render {



	GLTexture::GLTexture(IRenderModule* owner, std::shared_ptr<nether::Texture> tex)
		: Texture(owner)
		, m_texture(tex)
	{

	}

	math::Vec2i GLTexture::GetSize() const
	{
		int width, height;
		width = m_texture->GetWidth();
		height = m_texture->GetHeight();
		return { width, height };
	}

	std::shared_ptr<nether::Texture> GLTexture::GetNetherTexture()
	{
		return m_texture;
	}

}