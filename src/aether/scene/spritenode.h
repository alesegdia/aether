#pragma once

#include "aether/scene/SceneNode.h"


namespace aether::render
{
    class Texture;
}

namespace aether::scene
{


class ISpriteNode : public SceneNode
{
public:
    ISpriteNode(core::ModuleObject* o)
        : SceneNode(o)
    {

    }

    virtual void SetClippingRect(float x, float y, float w, float h) = 0;
    virtual void SetTexture(render::Texture* texture) = 0;
};



}
