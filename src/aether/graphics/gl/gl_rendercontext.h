#pragma once

#include "aether/graphics/rendercontext.h"
#include "aether/core/handledresourcemanager.h"

#include "Texture.h"

namespace aether::graphics {

	class GLRenderContext : public RenderContext
	{
	public:


	private:
		core::HandledResourceManager<nether::Texture*> texture_manager;


	};

}