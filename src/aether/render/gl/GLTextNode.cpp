#include "aether/render/gl/GLTextNode.h"

namespace aether::render {

    void GLTextNode::SetText(const std::string& text) {
        m_dirty = true;
        m_text = text;
    }

    void GLTextNode::SetSize(int size) {
        // TODO: Implement this method
    }

    void GLTextNode::SetColor(const glm::fvec4& color) {
        // TODO: Implement this method
    }

    void GLTextNode::SetAlignment(const glm::fvec2& alignment) {
        // TODO: Implement this method
    }

    void GLTextNode::SetFont(const std::string& font) {
        m_dirty = true;
    }

    void GLTextNode::SetLineSpacing(float spacing) {
        // TODO: Implement this method
    }

    void GLTextNode::SetClippingRect(float x, float y, float w, float h) {
        // TODO: Implement this method
    }

    ShaderProgram* GLTextNode::GetShader() const {
        // TODO: Implement this method
        return nullptr;
    }

    TextureConfig GLTextNode::GetTextureConfig() const {
        // TODO: Implement this method
        return TextureConfig();
    }

    void GLTextNode::Draw() {
        if (m_dirty)
        {
			m_currentTextData.Clean();
			m_currentTextData = m_font->CreateText(m_text, 0, 0, 1.0f, glm::fvec4(1.0f));
			m_dirty = false;
        }
        m_currentTextData.vao.Bind();
		glDrawArrays(GL_TRIANGLES, 0, m_currentTextData.vertices.size());
    }

}