#pragma once

#include <memory>
#include <vector>

#include "aether/math/vec.h"
#include "aether/core/ModuleObject.h"
#include "aether/render/Color.h"

#include "aether/core/utility.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

namespace aether::render
{
    class IRenderModule;
}

namespace aether::scene {


class SceneNode : public core::ModuleObject
{
public:

    SceneNode(core::ModuleObject* o) : core::ModuleObject(o) {}

    using Shared = std::shared_ptr<SceneNode>;

    virtual ~SceneNode();

    /// <summary>
    /// Retrieves the position of this node relative to its parent
    /// </summary>
    /// <returns></returns>
    const glm::vec3& GetRelativePosition() const;

    /// <summary>
    /// Renders the
    /// </summary>
    virtual void Render();

    const std::vector<SceneNode*>& GetChildren() const;

    SceneNode* GetParent();

    void SetParent(SceneNode* newParent);

    void AddChild(SceneNode* sceneNode);

    void ComputeRenderMatrix()
    {
        m_renderMatrix = m_parent != nullptr ? m_parent->GetModel() * GetModel() : GetModel();
    }

    void SetRelativePosition(glm::vec3 relativePosition)
    {
        if (relativePosition != m_relativePosition)
        {
            m_modelDirty = true;
            m_relativePosition = relativePosition;
        }
    }

    const glm::mat4x4& GetModel()
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

    void RemoveChild(SceneNode* child)
    {
        aether::core::remove_by_value(m_children, child);
    }

protected:

    SceneNode* m_parent{nullptr};
    render::Color m_color = render::Color(1.0f, 1.0f, 1.0f);
    std::vector<SceneNode*> m_children;
    
    bool m_modelDirty = true;
    glm::mat4x4 m_model = {};
    glm::vec3 m_scale = {};
    glm::vec3 m_rotation = {};
    glm::vec3 m_relativePosition = {};
    glm::mat4x4 m_renderMatrix = {};

};


}
