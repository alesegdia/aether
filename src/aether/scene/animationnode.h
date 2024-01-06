#pragma once

#include "../graphics/animation.h"
#include "texturenode.h"

namespace aether {
namespace scene {


class AnimationNode : public TextureNode
{
public:
    void SetAnimation(std::shared_ptr<graphics::Animation> anim)
    {
        anim->Reset(m_animationData);
        m_animation = anim;
    }

    void Render() override
    {
        if (m_animation != nullptr)
        {
            m_texregion = m_animationData.currentFrame->texture;
            TextureNode::Render();
        }
    }

    void Update(uint64_t delta)
    {
        if (m_animation != nullptr)
        {
            m_animation->UpdateData(m_animationData, delta);
        }
    }

private:
    std::shared_ptr<graphics::Animation> m_animation;
    graphics::AnimationData m_animationData;

};


}
}
