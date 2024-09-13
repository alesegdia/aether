#pragma once

#include "aether/scene/SceneNode.h"
#include "aether/graphics/spritesheet.h"

namespace aether {
namespace scene {


class SpriteNode : public SceneNode
{
public:
    SpriteNode(aether::graphics::Texture tex)
        : m_texture(tex)
    {

    }

    SpriteNode(std::shared_ptr<graphics::Spritesheet> sheet)
        : m_texture(tex)
    {

    }

    virtual ~SpriteNode()
    {

    }

    void SetTexture(const graphics::Texture& t)
    {

    }

    void SetClippingRect(const graphics::Texture& t)
    {

    }

protected:
    graphics::Texture m_texture;

};


}
}
