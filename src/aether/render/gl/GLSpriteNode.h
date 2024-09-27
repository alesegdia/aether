#pragma once

#include <nether/nether.h>

#include "aether/scene/spritenode.h"
#include "aether/render/gl/GLSceneNode.h"
#include "aether/render/IRenderModule.h"


namespace aether::render
{

	class GLSpriteNode : public scene::SpriteNode
	{
	public:
		GLSpriteNode(IRenderModule* owner, std::shared_ptr<nether::Texture> tex);
	};

}
