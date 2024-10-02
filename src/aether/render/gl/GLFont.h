#pragma once

#include "aether/render/Font.h"
#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>

#include <glm/glm.hpp>


namespace aether::render
{
	
	class IRenderModule;

	struct Character
	{
		unsigned int textureID;
		glm::ivec2 size;
		glm::ivec2 bearing;
		unsigned int advance;
	};

	class GLFont : public Font
	{
	public:
		GLFont(IRenderModule* owner, const std::string& path, int size);

	private:
		static constexpr int MAX_GLYPHS = 128;
		Character m_characters[MAX_GLYPHS];


	};

}
