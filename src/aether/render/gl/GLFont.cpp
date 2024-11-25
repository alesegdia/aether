#include "aether/render/gl/GLFont.h"
#include <glad/gl.h>
#include "aether/render/IRenderModule.h"
#include <string>
#include <ft2build.h>
#include "aether/core/logger.h"
#include "aether/render/gl/GLTexture.h"
#include FT_FREETYPE_H

namespace aether::render {

    FT_Library& get_ft()
    {
        static FT_Library ft;
        bool initialized = false;

        if (!initialized)
        {
            if (FT_Init_FreeType(&ft))
            {
                Logger::LogError() << "ERROR::FREETYPE: Could not init FreeType Library";
            }
            initialized = true;
        }
        return ft;
    }

    GLFont::GLFont(IRenderModule* owner, const std::string& path, int size)
        : Font(owner)
        , m_characters()
    {
        FT_Face face;
        if (FT_New_Face(get_ft(), path.c_str(), 0, &face))
        {
			Logger::LogError() << "ERROR::FREETYPE: Failed to load font " << path;
        }
        else
        {
            FT_Set_Pixel_Sizes(face, 0, size);

            int max_dim = (1 + (face->size->metrics.height >> 6)) * ceilf(sqrtf(MAX_GLYPHS));
            int tex_width = 1;
            while (tex_width < max_dim) tex_width <<= 1;
            int tex_height = tex_width;

            // render glyphs to atlas

            char* pixels = (char*)calloc(tex_width * tex_height, 1);
            int pen_x = 0, pen_y = 0;

            for (int i = 0; i < MAX_GLYPHS; ++i) {
                FT_Load_Char(face, i, FT_LOAD_RENDER | FT_LOAD_FORCE_AUTOHINT | FT_LOAD_TARGET_LIGHT);
                FT_Bitmap* bmp = &face->glyph->bitmap;

                if (pen_x + bmp->width >= tex_width) {
                    pen_x = 0;
                    pen_y += ((face->size->metrics.height >> 6) + 1);
                }

                for (int row = 0; row < bmp->rows; ++row) {
                    for (int col = 0; col < bmp->width; ++col) {
                        int x = pen_x + col;
                        int y = pen_y + row;
                        pixels[y * tex_width + x] = bmp->buffer[row * bmp->pitch + col];
                    }
                }

                // this is stuff you'd need when rendering individual glyphs out of the atlas

                m_glyphs[i].x0 = pen_x;
                m_glyphs[i].y0 = pen_y;
                m_glyphs[i].x1 = pen_x + bmp->width;
                m_glyphs[i].y1 = pen_y + bmp->rows;

                m_glyphs[i].x_off = face->glyph->bitmap_left;
                m_glyphs[i].y_off = face->glyph->bitmap_top;
                m_glyphs[i].advance = face->glyph->advance.x >> 6;

                Character character = {
                    0,
                    glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                    glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                    face->glyph->advance.x
                };
                m_characters[i] = character;

                pen_x += bmp->width + 1;
            }

            char* png_data = (char*)calloc(tex_width * tex_height * 4, 1);
            for (int i = 0; i < (tex_width * tex_height); ++i) {
                png_data[i * 4 + 0] |= 0xff;
                png_data[i * 4 + 1] |= 0xff;
                png_data[i * 4 + 2] |= 0xff;
                png_data[i * 4 + 3] |= pixels[i];
            }

            std::shared_ptr<nether::Texture> texture = std::make_shared<nether::Texture>();
            texture->Create(tex_width, tex_height, (unsigned char*)png_data, nether::TextureFormat::RGBA8);

            m_texture = new GLTexture(owner, texture);

            delete png_data;
        }

    }

    TextData GLFont::CreateText(const std::string& text, float x, float y, float scale, const glm::fvec4& color)
    {
        TextData td;

        // iterate through all characters
        std::string::const_iterator c;
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
        for (c = text.begin(); c != text.end(); c++)
        {
            Character ch = m_characters[*c];
			glyph_info gi = m_glyphs[*c];
            
            float u0 = float(gi.x0) / float(m_texture->GetSize().GetX());
            float u1 = float(gi.x1) / float(m_texture->GetSize().GetX());
            
            float v0 = float(gi.y0) / float(m_texture->GetSize().GetY());
            float v1 = float(gi.y1) / float(m_texture->GetSize().GetY());

            float xpos = x + ch.Bearing.x * scale;
            float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

            float w = ch.Size.x * scale;
            float h = ch.Size.y * scale;

            // update VBO for each character
            vertices.insert(vertices.end(), {
                xpos,         ypos,          0,  u0, v0,
                xpos + w,     ypos,          0,  u1, v0,
                xpos + w,     ypos + h,      0,  u1, v1,
                xpos,         ypos + h,      0,  u0, v1,
            });

			indices.insert(indices.end(), {
				0, 1, 2,
				2, 3, 0
			});

            x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64)
        }

		td.topology.SetVertexFormat(CreateP3U2VertexFormat());
        td.topology.SetIndices(indices);
		td.topology.SetVertices(vertices);
		td.topology.ConfigAndUpload();

        td.fontAtlasTexture = m_texture;

        return td;
    }


}
