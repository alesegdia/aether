#pragma once

#include "../graphics/animation.h"
#include "texturenode.h"

namespace aether {
namespace scene {


class AnimationNode : public TextureNode
{
public:
    void SetAnimation(graphics::Animation* anim)
    {
        anim->Reset(m_animationData);
        m_animation = anim;
    }

    void Render() override
    {
        m_texregion = m_animationData.currentFrame->texture;
        TextureNode::Render();
    }

    void Update(uint64_t delta);

private:
    graphics::Animation* m_animation;
    graphics::AnimationData m_animationData;

};


}
}
