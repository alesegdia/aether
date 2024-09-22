#pragma once

#include "aether/render/Font.h"

#include "aether/render/IRenderModule.h"

#include <ft2build.h>
#include FT_FREETYPE_H

namespace aether::render
{

	class GLFont : public Font
	{
	public:
		GLFont(IRenderModule* owner, FT_Face face)
			: Font(owner)
		{

		}

	private:
		FT_Face m_face;

	};

}
