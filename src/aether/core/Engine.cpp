#include "aether/core/Engine.h"


namespace {
	aether::Engine s_engine;
}

namespace aether
{
	Engine* GEngine = nullptr;

	void init_engine()
	{
		GEngine = &s_engine;
		s_engine.Init();
	}

	Engine* get_engine()
	{
		return &s_engine;
	}

	scene::Scene& get_scene()
	{
		return s_engine.GetWorld()->GetScene();
	}

}
