#pragma once

#include "../graphics/animation.h"
#include "texturenode.h"

namespace aether {
namespace scene {


class AnimationNode : public TextureNode
{
public:
    void setAnimation(graphics::Animation* anim)
    {
        anim->reset(m_animationData);
        m_animation = anim;
    }

    void render() override
    {
        m_texregion = m_animationData.currentFrame->texture;
        TextureNode::render();
    }

    void update(uint64_t delta);

private:
    graphics::Animation* m_animation;
    graphics::AnimationData m_animationData;

};


}
}
