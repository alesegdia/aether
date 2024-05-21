#pragma once


#include "scene.h"


namespace aether {
namespace scene {


class CircleSceneNode : public SceneNode
{
public:
    CircleSceneNode(float radius, aether::graphics::Color color)
        : m_radius(radius)
        , m_color(color)
    {

    }

    virtual ~CircleSceneNode() {}

    void Render() override
    {
        aether::graphics::draw_filled_circle(m_renderPosition, m_radius, m_color);
    }


private:
    float m_radius = 0.f;
    aether::graphics::Color m_color;

};


}
}
