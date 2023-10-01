#pragma once

#include <memory>
#include <vector>

#include "../math/vec.h"
#include "../graphics/color.h"
#include "../core/utility.h"


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

protected:

    SceneNode::Shared m_parent{nullptr};
    graphics::Color m_color = graphics::Color(1.0f, 1.0f, 1.0f);
    std::vector<SceneNode::Shared> m_children;

    int m_zIndex;
    math::Vec2f m_relativePosition;
    math::Vec2f m_renderPosition;
    math::Vec2f m_center;
    float m_angle = 0.0f;


};


class Scene
{
public:
    Scene()
    {
        m_root = std::make_shared<SceneNode>();
        m_root->SetParent(std::make_shared<SceneNode>());
    }

    void Render()
    {
        m_nodesSortedByZindex.clear();
        Traverse(m_root);
        for( auto child : m_nodesSortedByZindex ) {
            child->Render();
        }
    }

    void Traverse(const SceneNode::Shared& node)
    {
        /*
        core::insert_sorted(m_nodesSortedByZindex, node, [](auto val,  auto iter) {
            return val->zIndex() < iter->zIndex();
        });
        node->renderPos() = node->parent()->renderPos() + node->relativePos();
        for( auto child : node->children() ) {
            traverse(child);
        }
        */
    }

    template <typename SceneNodeType, typename... Args>
    std::shared_ptr<SceneNodeType> AddToScene(Args&&... args)
    {
        auto ptr = std::make_shared<SceneNodeType>(args...);
        m_root->AddChild(ptr);
        ptr->SetParent(m_root);
        return ptr;
    }

private:
    SceneNode::Shared m_root;
    std::vector<SceneNode::Shared> m_nodesSortedByZindex;

};




}
}
