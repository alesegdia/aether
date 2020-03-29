#pragma once


#include "../graphics/texture.h"
#include "scene.h"


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

    void set(const graphics::TextureRegion& tr);

    void render() override;

protected:
    graphics::TextureRegion m_texregion;

};



}
}
