#include "SceneNode.h"
#include "aether/core/utility.h"


namespace aether::scene {


SceneNode::~SceneNode()
{

}

const glm::vec3& SceneNode::GetRelativePosition() const
{
    return m_relativePosition;
}

void SceneNode::Render()
{

}

const std::vector<SceneNode*>& SceneNode::GetChildren() const
{
    return m_children;
}

SceneNode* SceneNode::GetParent()
{
    return m_parent;
}

void SceneNode::SetParent(SceneNode* newParent)
{
    if( m_parent != nullptr ) {
        m_parent->RemoveChild(this);
    }
    newParent->AddChild(this);
    m_parent = newParent;
}

void SceneNode::AddChild(SceneNode* sceneNode)
{
    m_children.push_back(sceneNode);
}


}
