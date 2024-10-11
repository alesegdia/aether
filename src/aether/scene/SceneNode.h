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
} // namespace aether::render

namespace aether::scene {

    /**
     * @brief Represents a node in the scene graph.
     */
    class SceneNode : public core::ModuleObject
    {
    public:

        /**
         * @brief Constructs a SceneNode object.
         * @param o Pointer to the parent ModuleObject.
         */
        SceneNode(core::ModuleObject* o) : core::ModuleObject(o) {}

        using Shared = std::shared_ptr<SceneNode>;

        /**
         * @brief Destroys the SceneNode object.
         */
        virtual ~SceneNode();

        /**
         * @brief Retrieves the position of this node relative to its parent.
         * @return The relative position as a glm::vec3.
         */
        const glm::vec3& GetRelativePosition() const;

        /**
         * @brief Retrieves the children of this node.
         * @return A vector of pointers to the child nodes.
         */
        const std::vector<SceneNode*>& GetChildren() const;

        /**
         * @brief Retrieves the parent of this node.
         * @return Pointer to the parent node.
         */
        SceneNode* GetParent();

        /**
         * @brief Sets the parent of this node.
         * @param newParent Pointer to the new parent node.
         */
        void SetParent(SceneNode* newParent);

        /**
         * @brief Adds a child node to this node.
         * @param sceneNode Pointer to the child node to be added.
         */
        void AddChild(SceneNode* sceneNode);

        /**
         * @brief Computes the render matrix for this node.
         */
        void ComputeRenderMatrix();

        /**
         * @brief Sets the position of this node relative to its parent.
         * @param relativePosition The new relative position as a glm::vec3.
         */
        void SetRelativePosition(glm::vec3 relativePosition);

        /**
         * @brief Retrieves the model matrix of this node.
         * @return The model matrix as a glm::mat4x4.
         */
        const glm::mat4x4& GetModel();

        /**
         * @brief Removes a child node from this node.
         * @param child Pointer to the child node to be removed.
         */
        void RemoveChild(SceneNode* child);

    protected:

        SceneNode* m_parent{ nullptr }; ///< Pointer to the parent node.
        render::Color m_color = render::Color(1.0f, 1.0f, 1.0f); ///< Color of the node.
        std::vector<SceneNode*> m_children; ///< Vector of pointers to the child nodes.

        bool m_modelDirty = true; ///< Flag indicating if the model matrix needs to be recomputed.
        glm::mat4x4 m_model = {}; ///< Model matrix of the node.
        glm::vec3 m_scale = {}; ///< Scale of the node.
        glm::vec3 m_rotation = {}; ///< Rotation of the node.
        glm::vec3 m_relativePosition = {}; ///< Position of the node relative to its parent.
        glm::mat4x4 m_renderMatrix = {}; ///< Render matrix of the node.

    };

} // namespace aether::scene