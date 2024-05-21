#pragma once


#include "../graphics/texture.h"

#include "aether/scene/SceneNode.h"

namespace aether {
namespace scene {


class TextureNode : public SceneNode
{
public:
    TextureNode(const graphics::TextureRegion& texregion)
        : m_texregion(texregion)
    {

    }

    virtual ~TextureNode()
    {

    }

    void SetTextureRegion(const graphics::TextureRegion& tr);

    void Render() override;

protected:
    graphics::TextureRegion m_texregion;

};


}
}
