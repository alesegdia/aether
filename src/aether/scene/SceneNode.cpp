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

inline void SceneNode::ComputeRenderMatrix()
{
    m_renderMatrix = m_parent != nullptr ? m_parent->GetModel() * GetModel() : GetModel();
}

void SceneNode::SetRelativePosition(glm::vec3 relativePosition)
{
    if (relativePosition != m_relativePosition)
    {
        m_modelDirty = true;
        m_relativePosition = relativePosition;
    }
}

const glm::mat4x4& SceneNode::GetModel()
{
    if (m_modelDirty)
    {
        m_model = glm::mat4(1.0f);
        m_model = glm::scale(m_model, m_scale);
        m_model = glm::rotate(m_model, m_rotation[0], glm::vec3(1.f, 0.f, 0.f));
        m_model = glm::rotate(m_model, m_rotation[1], glm::vec3(0.f, 1.f, 0.f));
        m_model = glm::rotate(m_model, m_rotation[2], glm::vec3(0.f, 0.f, 1.f));
        m_model = glm::translate(m_model, m_relativePosition);
        m_modelDirty = false;
    }
    return m_model;
}

inline void SceneNode::RemoveChild(SceneNode* child)
{
    aether::core::remove_by_value(m_children, child);
}


}
