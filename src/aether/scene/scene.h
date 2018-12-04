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

    using Shared = std::shared_ptr<SceneNode>;

    virtual ~SceneNode();

    math::Vec2f& relativePos();

    const math::Vec2f& relativePos() const;

    math::Vec2f& renderPos();

    const math::Vec2f& renderPos() const;

    int zIndex() const;

    void zIndex(int pzindex);

    virtual void render();

    std::vector<SceneNode::Shared>& children();

    SceneNode::Shared& parent();

    void parent(Shared newParent);

    void addChild(const SceneNode::Shared& sceneNode);

private:

    SceneNode::Shared m_parent{nullptr};
    graphics::Color m_color;
    std::vector<SceneNode::Shared> m_children;

    int m_zIndex;
    math::Vec2f m_relativePosition;
    math::Vec2f m_renderPosition;
    float angle = 0.0f;


};


class Scene
{
public:
    Scene()
    {
        m_root = std::make_shared<SceneNode>();
        m_root->parent(std::make_shared<SceneNode>());
    }

    void render()
    {
        m_nodesSortedByZindex.clear();
        traverse(m_root);
        for( auto child : m_nodesSortedByZindex ) {
            child->render();
        }
    }

    void traverse(const SceneNode::Shared& node)
    {
        core::insert_sorted(m_nodesSortedByZindex, node, [](auto val,  auto iter) {
            return val->zIndex();
        });
        node->renderPos() = node->parent()->renderPos() + node->relativePos();
        for( auto child : node->children() ) {
            traverse(child);
        }
    }

    template <typename SceneNodeType, typename... Args>
    std::shared_ptr<SceneNodeType> addToScene(Args&&... args)
    {
        auto ptr = std::make_shared<SceneNodeType>(args...);
        m_root->addChild(ptr);
        ptr->parent(m_root);
        return ptr;
    }

private:
    SceneNode::Shared m_root;
    std::vector<SceneNode::Shared> m_nodesSortedByZindex;

};




}
}
