#pragma once

#include <string>

#include "aether/graphics/texture.h"

namespace aether::graphics {

	class RenderContext
	{
	public:
		virtual Texture LoadTexture(const std::string& path) = 0;
	};

}