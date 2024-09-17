#pragma once

#include "aether/scene/SceneNode.h"
#include "aether/core/ModuleObject.h"

namespace aether::render {

    class GLSceneNode : public scene::SceneNode, core::ModuleObject
    {
    public:
        GLSceneNode(ModuleObject* o) : ModuleObject(o) {}

        virtual ~GLSceneNode()
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
