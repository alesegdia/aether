#pragma once

#include "aether/core/ModuleObject.h"
#include "aether/core/handledresourcemanager.h"

#include "aether/graphics/IRenderModule.h"

#include <nether/nether.h>

namespace aether::graphics {

	class GLRenderContext : public IRenderModule
	{
	public:
		std::shared_ptr<Texture> LoadTextureFromFile(const std::string& path) override
		{
			
		}
	};

}