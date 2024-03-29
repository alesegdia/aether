#pragma once

#include "../graphics/animation.h"
#include "texturenode.h"

namespace aether {
namespace scene {

    class CircleShapeNode : public SceneNode
    {
    public:
        CircleShapeNode(float radius)
            : m_radius(radius)
        {

        }

        void Render() override
        {
            aether::graphics::draw_filled_circle(m_renderPosition.GetX(), m_renderPosition.GetY(), m_radius, m_color);
        }

    private:
        float m_radius = 32.0f;
        graphics::Color m_color;

    };

    class RectShapeNode : public SceneNode
    {
    public:
        RectShapeNode(aether::math::Vec2i size)
            : m_size(size)
        {

        }

        void Render() override
        {
            aether::graphics::draw_filled_rectangle(m_renderPosition.GetX() - 8, m_renderPosition.GetY() - 8, m_renderPosition.GetX() + m_size.GetX() - 8, m_renderPosition.GetY() + m_size.GetY() - 8, m_color);
            //aether::graphics::draw_filled_circle(m_renderPosition.GetX(), m_renderPosition.GetY(), 16, m_color);
        }

    private:
        aether::math::Vec2i m_size;
        graphics::Color m_color;

    };

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
