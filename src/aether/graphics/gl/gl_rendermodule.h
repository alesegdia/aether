#pragma once

#include "aether/graphics/rendercontext.h"
#include "aether/core/handledresourcemanager.h"

#include <nether/nether.h>

namespace aether::graphics {

	class GLRenderContext : public RenderContext
	{
	public:
		Texture Load(const std::string& path)
		{

		}

	private:
		core::HandledResourceManager<nether::Texture*> texture_manager;


	};

}