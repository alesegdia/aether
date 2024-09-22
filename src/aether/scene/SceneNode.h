#pragma once

#include <memory>
#include <vector>

#include "aether/math/vec.h"
#include "aether/core/ModuleObject.h"
#include "aether/render/Color.h"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi


namespace aether::scene {

    class IRenderModule;

class SceneNode : public core::ModuleObject
{
public:

    SceneNode(core::ModuleObject* o) : core::ModuleObject(o) {}

    IRenderModule* GetRenderer() const;

    using Shared = std::shared_ptr<SceneNode>;

    virtual ~SceneNode();

    /// <summary>
    /// Retrieves the position of this node relative to its parent
    /// </summary>
    /// <returns></returns>
    math::Vec2f& GetRelativePosition();

    /// <summary>
    /// Retrieves the position of this node relative to its parent
    /// </summary>
    /// <returns></returns>
    const math::Vec2f& GetRelativePosition() const;

    /// <summary>
    /// Retrieves the final rendering position
    /// </summary>
    /// <returns></returns>
    math::Vec2f& GetRenderPosition();

    /// <summary>
    /// Retrieves the final rendering position
    /// </summary>
    /// <returns></returns>
    const math::Vec2f& GetRenderPosition() const;

    /// <summary>
    /// Renders the
    /// </summary>
    virtual void Render();

    std::vector<SceneNode::Shared>& GetChildren();

    SceneNode::Shared& GetParent();

    void SetParent(Shared newParent);

    void AddChild(const SceneNode::Shared& sceneNode);

    float& GetAngle()
    {
        return m_angle;
    }

    void SetRenderMatrix(const glm::mat4& parentMatrix)
    {
        m_renderMatrix = parentMatrix * GetModel();
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

protected:

    SceneNode::Shared m_parent{nullptr};
    render::Color m_color = render::Color(1.0f, 1.0f, 1.0f);
    std::vector<SceneNode::Shared> m_children;
    
    bool m_modelDirty = true;
    glm::mat4x4 m_model;
    glm::vec3 m_scale;
    glm::vec3 m_rotation;
    glm::vec3 m_relativePosition;
    glm::mat4x4 m_renderMatrix;

    int m_zIndex = 0;
    math::Vec2f m_center;
    float m_angle = 0.0f;


};


}
