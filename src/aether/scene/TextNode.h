#pragma once

#include "aether/scene/SceneNode.h"
#include "aether/render/TextureRegion.h"
#include "aether/render/Font.h"

namespace aether::scene {

    class TextNode : public SceneNode
    {
    public:
        TextNode(std::shared_ptr<render::Texture> tex)
        {
            m_texRegion = std::make_unique<render::TextureRegion>();
        }

        virtual ~TextNode()
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
