#pragma once

#include "aether/scene/ITextNode.h"
#include "aether/scene/SceneNode.h"

namespace aether::render {

    class GLTextNode : public scene::ITextNode
    {
    public:
        GLTextNode(ModuleObject* o)
            : scene::ITextNode(o)
        {

        }

        virtual ~GLTextNode()
        {

        }


        void SetText(const std::string& text) override = 0;
        void SetSize(int size) override = 0;
        void SetColor(const glm::fvec4& color) override = 0;
        void SetAlignment(const glm::fvec2& alignment) override = 0;
        void SetFont(const std::string& font) override = 0;
        void SetLineSpacing(float spacing) override = 0;
        void SetClippingRect(float x, float y, float w, float h) override = 0;



    protected:
        std::string m_text;

    };


}
