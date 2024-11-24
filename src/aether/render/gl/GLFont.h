#pragma once

#include "aether/render/Font.h"
#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>

#include <glm/glm.hpp>

#include <nether/nether.h>


namespace aether::render
{

	class GLTexture;
	class IRenderModule;

	struct Character {
		unsigned int TextureID;  // ID handle of the glyph texture
		glm::ivec2   Size;       // Size of glyph
		glm::ivec2   Bearing;    // Offset from baseline to left/top of glyph
		unsigned int Advance;    // Offset to advance to next glyph
	};

	struct glyph_info {
		int x0, y0, x1, y1;	// coords of glyph in the texture atlas
		int x_off, y_off;   // left & top bearing when rendering
		int advance;        // x advance when rendering
	};

	struct TextData
	{
		void Clean()
		{
			vao.Delete();
			vbo.Delete();
		}
		GLTexture* fontAtlasTexture;
		nether::VertexArrayObject vao;
		nether::BufferObject vbo;
		std::vector<float> vertices;
	};

	class GLFont : public Font
	{
	public:
		GLFont(IRenderModule* owner, const std::string& path, int size = 48);

		TextData CreateText(const std::string& text, float x, float y, float scale, const glm::fvec4& color);

	private:
		static constexpr int MAX_GLYPHS = 128;
		Character m_characters[MAX_GLYPHS];
		glyph_info m_glyphs[MAX_GLYPHS];
		aether::render::GLTexture* m_texture;

	};

}
