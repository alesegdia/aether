#include "aether/scene/spritenode.h"
#include <cassert>
#include "aether/core/Engine.h"



namespace aether::scene
{
    ISpriteNode::ISpriteNode(core::ModuleObject* o)
        : SceneNode(o)
    {
    }

    void ISpriteNode::SetAnimation(std::shared_ptr<render::Animation> anim)
    {
        m_currentAnimation = anim;
        m_currentAnimation->Reset(m_animationData);
        SetTextureRegion(&(m_animationData.currentFrame->texture));
    }

    void ISpriteNode::PlayAnimation(const std::string& animationName)
    {
        assert(m_animations.find(animationName) != m_animations.end());
        SetAnimation(m_animations[animationName]);
    }

    void ISpriteNode::Step()
    {
        if (m_currentAnimation)
        {
            auto prevFrame = m_animationData.currentFrame;
            m_currentAnimation->UpdateData(m_animationData, aether::GEngine->GetDeltaTimeInMicroseconds());
            if (m_animationData.currentFrame != prevFrame)
            {
                auto clip = m_animationData.currentFrame->texture.GetClip();
                SetTexture(m_animationData.currentFrame->texture.GetTexture());
                SetClippingRect(clip.x(), clip.y(), clip.w(), clip.h());
            }
        }
    }

    void ISpriteNode::LoadAllAnimations(const render::AsepriteAnimationData& data)
    {
        for (auto& anim : data.anims)
        {
            AddAnimation(anim.first, anim.second);
        }
    }

    void ISpriteNode::AddAnimation(const std::string& name, std::shared_ptr<render::Animation> anim)
    {
        m_animations[name] = anim;
    }
}