#pragma once

#include "aether/scene/SceneNode.h"
#include "aether/render/TextureRegion.h"

namespace aether::scene {


class SpriteNode : public SceneNode
{
public:
    SpriteNode(core::ModuleObject* o, std::shared_ptr<render::Texture> tex)
        : SceneNode(o)
    {
        m_texRegion = std::make_unique<render::TextureRegion>();
    }

    virtual ~SpriteNode()
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

protected:
    std::unique_ptr<render::TextureRegion> m_texRegion;

};


}
