#include "scene.h"



namespace aether {
namespace scene {

SceneNode::~SceneNode()
{

}

math::Vec2f &SceneNode::GetRelativePosition()
{
    return m_relativePosition;
}

const math::Vec2f &SceneNode::GetRelativePosition() const
{
    return m_relativePosition;
}

math::Vec2f &SceneNode::GetRenderPosition()
{
    return m_renderPosition;
}

const math::Vec2f &SceneNode::GetRenderPosition() const
{
    return m_renderPosition;
}

int SceneNode::GetZIndex() const
{
    return m_zIndex;
}

void SceneNode::SetZIndex(int pzindex)
{
    m_zIndex = pzindex;
}

void SceneNode::Render()
{

}

std::vector<SceneNode::Shared> &SceneNode::GetChildren()
{
    return m_children;
}

SceneNode::Shared &SceneNode::GetParent()
{
    return m_parent;
}

void SceneNode::SetParent(SceneNode::Shared newParent)
{
    if( m_parent != nullptr ) {
        auto me = shared_from_this();
        core::remove_by_value(m_parent->GetChildren(), me);
    }
    newParent->AddChild(shared_from_this());
    m_parent = newParent;
}

void SceneNode::AddChild(const SceneNode::Shared &sceneNode)
{
    m_children.push_back(sceneNode);
}


}
}
