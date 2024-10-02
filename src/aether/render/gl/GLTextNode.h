#pragma once

#include "aether/scene/TextNode.h"
#include "aether/scene/SceneNode.h"

namespace aether::render {

    class GLTextNode : public scene::SceneNode
    {
    public:
        GLTextNode(ModuleObject* o)
            : scene::SceneNode(o)
        {
            m_texRegion = std::make_unique<render::TextureRegion>();
        }

        virtual ~GLTextNode()
        {

        }

        void SetText(const std::string& text)
        {
            m_text = text;
        }

        void SetFont(render::Font* font)
        {
            m_font = font;
        }

    protected:
        std::unique_ptr<render::TextureRegion> m_texRegion;
        std::string m_text;
        render::Font* m_font;

    };


}
