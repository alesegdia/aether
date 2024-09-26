#include "GLTexture.h"

namespace aether::render {



	inline GLSpriteNode::GLSpriteNode(IRenderModule* owner, std::shared_ptr<nether::Texture> tex)
		: Texture(owner)
	{

	}

	math::Vec2i GLSpriteNode::GetSize() const
	{
		int width, height;
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);
		return { width, height };
	}

}