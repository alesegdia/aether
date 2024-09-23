#include "aether/core/Engine.h"

namespace {
	aether::Engine s_engine;
}

namespace aether
{
	void init()
	{

	}

	Engine* get_engine()
	{
		return &s_engine;
	}
}
