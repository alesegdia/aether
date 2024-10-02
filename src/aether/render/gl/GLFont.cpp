#include "aether/render/gl/GLFont.h"
#include <glad/gl.h>
#include "aether/render/IRenderModule.h"
#include <string>
#include <ft2build.h>
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
                printf("ERROR::FREETYPE: Could not init FreeType Library\n");
            }
            initialized = true;
        }
        return ft;
    }

    GLFont::GLFont(IRenderModule* owner, const std::string& path, int size)
        : Font(owner)
    {
        FT_Face face;
        if (FT_New_Face(get_ft(), path.c_str(), 0, &face))
        {
            printf("ERROR::FREETYPE: Failed to load font\n");
        }

        FT_Set_Pixel_Sizes(face, 0, size);

        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

        for (unsigned char c = 0; c < 128; c++)
        {
            // load character glyph 
            if (FT_Load_Char(face, c, FT_LOAD_RENDER))
            {
                std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
                continue;
            }
            // generate texture
            unsigned int texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
            );
            // set texture options
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            // now store character for later use
            Character character = {
                texture,
                glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                face->glyph->advance.x
            };
            assert(c >= 0 && c < MAX_GLYPHS);
            m_characters[size_t(c)] = character;
        }

        FT_Done_Face(face);
    }

}
