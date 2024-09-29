#pragma once


namespace aether::render
{
    class Texture;
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
