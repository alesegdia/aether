#pragma once

#include "aether/render/texture.h"


namespace aether::render
{

	RenderModule* Texture::GetRenderer() const { return (RenderModule*)owner; }


}

