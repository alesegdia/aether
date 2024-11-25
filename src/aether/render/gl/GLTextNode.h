#pragma once

#include "aether/scene/ITextNode.h"
#include "aether/scene/SceneNode.h"
#include "aether/render/IBatchedEntity.h"
#include "aether/render/gl/GLShaderProgram.h"
#include "aether/render/gl/GLFont.h"

namespace aether::render {

    class GLTextNode : public scene::ITextNode, public render::IBatchedEntity
    {
    public:
        GLTextNode(ModuleObject* o, GLShaderProgram* shader)
            : scene::ITextNode(o)
            , m_shader(shader)
        {
        }

        virtual ~GLTextNode()
        {

        }

        // ITextNode interface
        void SetText(const std::string& text) override;
        void SetSize(int size) override;
        void SetColor(const glm::fvec4& color) override;
        void SetAlignment(const glm::fvec2& alignment) override;
        void SetFont(const std::string& fontPath) override;
        void SetLineSpacing(float spacing) override;
        void SetClippingRect(float x, float y, float w, float h) override;

		// IBatchedEntity interface
        ShaderProgram* GetShader() const override;
        TextureConfig GetTextureConfig() const override;
        void Draw() override;

    protected:
		bool m_dirty = true;
        std::string m_text;
        aether::render::TextData m_currentTextData;
        GLFont* m_font;
        aether::render::GLShaderProgram* m_shader;
        TextureConfig m_textureConfig;

    };


}
