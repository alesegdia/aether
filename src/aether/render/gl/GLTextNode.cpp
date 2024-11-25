#include "aether/render/gl/GLTextNode.h"
#include "aether/render/gl/GLTexture.h"
#include "aether/core/Engine.h"
#include "aether/render/texture.h"

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

    void GLTextNode::SetFont(const std::string& fontPath) {
        Font* font = aether::GEngine->GetAssetsManager()->GetAsset<Font>(fontPath);
		m_font = static_cast<GLFont*>(font);
        m_dirty = true;
    }

    void GLTextNode::SetLineSpacing(float spacing) {
        // TODO: Implement this method
    }

    void GLTextNode::SetClippingRect(float x, float y, float w, float h) {
        // TODO: Implement this method
    }

    ShaderProgram* GLTextNode::GetShader() const {
        return m_shader;
    }

    TextureConfig GLTextNode::GetTextureConfig() const {
        return m_textureConfig;
    }

    void GLTextNode::Draw() {
        if (m_font == nullptr)
        {
            aether::Logger::LogError() << "Font is null in the GLTextNode.";
            aether::Logger::LogError() << "  - Check that the asset path has been loaded.\n";
            aether::Logger::LogError() << "";
        }
        else
        {
            if (m_dirty)
            {
                m_currentTextData.Clean();
                m_currentTextData = m_font->CreateText(m_text, 0, 0, 1.0f, glm::fvec4(1.0f));
                m_dirty = false;
                m_textureConfig = {};
                m_textureConfig.AddEntrySorted(1, m_currentTextData.fontAtlasTexture);
            }
            
            m_currentTextData.topology.Draw();
        }
    }

}