#pragma once

#include "aether/render/texture.h"
#include "aether/render/IRenderModule.h"

namespace aether::render
{

	IRenderModule* Texture::GetRenderer() const { return (IRenderModule*)owner; }

}
