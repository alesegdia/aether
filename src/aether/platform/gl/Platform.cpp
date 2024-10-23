#include "aether/platform.h"

#include "aether/render/gl/GLRenderModule.h"
#include "aether/core/gl/gl_application.h"

namespace aether
{
	namespace render
	{
		class IRenderModule;
	}

	core::ApplicationBase* CreateApp(int sw, int sh)
	{
		return new core::Application(sw, sh);
	}

	render::IRenderModule* CreateRenderModule()
	{
		return new render::GLRenderModule();
	}

}

