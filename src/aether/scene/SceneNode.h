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

    void ComputeRenderMatrix();

    void SetRelativePosition(glm::vec3 relativePosition);

    const glm::mat4x4& GetModel();

    void RemoveChild(SceneNode* child);

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
