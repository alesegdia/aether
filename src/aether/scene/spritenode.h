#pragma once

#include "aether/scene/SceneNode.h"
#include "aether/render/TextureRegion.h"

namespace aether::render
{
    class Sprite : public core::ModuleObject
    {
    public:
        Sprite(core::ModuleObject* o, render::Texture* tex)
            : core::ModuleObject(o)
        {
            m_texRegion = std::make_unique<render::TextureRegion>();
            m_texRegion->SetTexture(tex);
            AdjustClippingRectToTexture();
        }

        virtual ~Sprite()
        {

        }

        void SetTexture(render::Texture* t)
        {
            m_texRegion->SetTexture(t);
        }

        void AdjustClippingRectToTexture()
        {
            auto sz = m_texRegion->GetTexture()->GetSize();
            m_texRegion->SetClip(0, 0, sz.GetX(), sz.GetY());
        }

        void SetClippingRect(float x, float y, float w, float h)
        {
            m_texRegion->SetClip(aether::math::Rectf(x, y, w, h));
        }

        const std::unique_ptr<render::TextureRegion>& GetRegion()
        {
            return m_texRegion;
        }

    protected:
        std::unique_ptr<render::TextureRegion> m_texRegion;

    };

}

namespace aether::scene
{


class ISpriteNode
{
public:
    virtual void SetClippingRect(float x, float y, float w, float h) = 0;
    virtual void SetTexture(render::Texture* texture) = 0;
};



}
