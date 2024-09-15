#pragma once

#include "aether/scene/SceneNode.h"
#include "aether/graphics/spritesheet.h"

namespace aether {
namespace scene {


class SpriteNode : public SceneNode
{
public:
    SpriteNode(std::shared_ptr<graphics::Texture> tex)
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
    std::shared_ptr<graphics::Texture> m_texture;

};


}
}
