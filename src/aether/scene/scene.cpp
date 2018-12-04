#include "scene.h"



namespace aether {
namespace scene {

SceneNode::~SceneNode()
{

}

math::Vec2f &SceneNode::relativePos()
{
    return m_relativePosition;
}

const math::Vec2f &SceneNode::relativePos() const
{
    return m_relativePosition;
}

math::Vec2f &SceneNode::renderPos()
{
    return m_renderPosition;
}

const math::Vec2f &SceneNode::renderPos() const
{
    return m_renderPosition;
}

int SceneNode::zIndex() const
{
    return m_zIndex;
}

void SceneNode::zIndex(int pzindex)
{
    m_zIndex = pzindex;
}

void SceneNode::render()
{

}

std::vector<SceneNode::Shared> &SceneNode::children()
{
    return m_children;
}

SceneNode::Shared &SceneNode::parent()
{
    return m_parent;
}

void SceneNode::parent(SceneNode::Shared newParent)
{
    if( m_parent != nullptr ) {
        auto me = shared_from_this();
        core::remove_by_value(m_parent->children(), me);
        m_parent = newParent;
        newParent->children().push_back(shared_from_this());
    }
    m_parent = newParent;
}

void SceneNode::addChild(const SceneNode::Shared &sceneNode)
{
    m_children.push_back(sceneNode);
}


}
}
