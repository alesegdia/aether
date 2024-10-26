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
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
		return { width, height };
	}

	std::shared_ptr<nether::Texture> GLTexture::GetNetherTexture()
	{
		return m_texture;
	}

}