#pragma once


#include "../graphics/texture.h"
#include "scene.h"


namespace aether {
namespace scene {



class TextureNode : public SceneNode
{
public:
    void render() override
    {
        m_texture.draw(renderPos().x(), renderPos().y());
    }

protected:
    graphics::Texture m_texture;

};



}
}
