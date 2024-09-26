#include "GLSpriteNode.h"

namespace aether::render
{

	inline GLSpriteNode::GLSpriteNode(IRenderModule* owner, std::shared_ptr<Texture> tex)
		: GLSceneNode(owner)
		, scene::SpriteNode(owner, tex)
	{

	}


}
