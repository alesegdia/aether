#pragma once

#include <memory>
#include <vector>

#include "aether/math/vec.h"
#include "aether/graphics/color.h"
#include "aether/graphics/graphics.h"
#include "aether/core/utility.h"


namespace aether {
namespace scene {


class SceneNode : public std::enable_shared_from_this<SceneNode>
{
public:

    SceneNode() = default;

    using Shared = std::shared_ptr<SceneNode>;

    virtual ~SceneNode();

    math::Vec2f& GetRelativePosition();

    const math::Vec2f& GetRelativePosition() const;

    math::Vec2f& GetRenderPosition();

    const math::Vec2f& GetRenderPosition() const;

    int GetZIndex() const;

    void SetZIndex(int pzindex);

    virtual void Render();

    std::vector<SceneNode::Shared>& GetChildren();

    SceneNode::Shared& GetParent();

    void SetParent(Shared newParent);

    void AddChild(const SceneNode::Shared& sceneNode);

    float& GetAngle()
    {
        return m_angle;
    }

    void SetRenderPosition(math::Vec2f renderPosition)
    {
        m_renderPosition = renderPosition;
    }

    void SetRelativePosition(math::Vec2f relativePosition)
    {
        m_relativePosition = relativePosition;
        if (relativePosition != m_relativePosition)
        {
            m_dirty = true;
        }
    }

    // clears the dirty boolean value
    // returns true if the dirty was set to false, and false if the dirty was already cleared
    bool ClearDirty()
    {
        if (!m_dirty)
        {
            return false;
        }
        m_dirty = true;
        return true;
    }

protected:

    SceneNode::Shared m_parent{nullptr};
    graphics::Color m_color = graphics::Color(1.0f, 1.0f, 1.0f);
    std::vector<SceneNode::Shared> m_children;
    bool m_dirty;

    int m_zIndex;
    math::Vec2f m_relativePosition;
    math::Vec2f m_renderPosition;
    math::Vec2f m_center;
    float m_angle = 0.0f;


};


class Scene
{
public:
    using SharedPtr = std::shared_ptr<Scene>;

    Scene()
    {
        m_root = std::make_shared<SceneNode>();
        m_root->SetParent(std::make_shared<SceneNode>());
    }

    void Render()
    {
        aether::graphics::clear(m_clearColor);
        m_nodesSortedByZindex.clear();
        Traverse(m_root);
        for( auto child : m_nodesSortedByZindex ) {
            child->Render();
        }
    }

    void Traverse(const SceneNode::Shared& node)
    {
        core::insert_sorted(m_nodesSortedByZindex, node, [](auto val,  auto iter) {
            return val->GetZIndex() < iter->GetZIndex();
        });
        auto parent = node->GetParent();
        auto newRenderPosition = (parent == nullptr ? node->GetRelativePosition() : parent->GetRelativePosition() + node->GetRelativePosition());
        node->SetRenderPosition(newRenderPosition);
        for( auto child : node->GetChildren() ) {
            Traverse(child);
        }
    }

    template <typename SceneNodeType, typename... Args>
    std::shared_ptr<SceneNodeType> AddToScene(Args&&... args)
    {
        auto ptr = std::make_shared<SceneNodeType>(args...);
        m_root->AddChild(ptr);
        ptr->SetParent(m_root);
        return ptr;
    }

    void AddToScene(std::shared_ptr<SceneNode> sceneNode)
    {
        m_root->AddChild(sceneNode);
        sceneNode->SetParent(m_root);
    }

private:
    SceneNode::Shared m_root;
    std::vector<SceneNode::Shared> m_nodesSortedByZindex;
    aether::graphics::Color m_clearColor = aether::graphics::Color::Magenta;

};




}
}
