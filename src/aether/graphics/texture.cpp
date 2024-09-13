#pragma once

#include "aether/graphics/texture.h"


namespace aether::graphics
{

	RenderModule* Texture::GetRenderer() const { return (RenderModule*)owner; }

}

