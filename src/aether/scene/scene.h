#pragma once

#include <memory>
#include <vector>

#include "../math/vec.h"
#include "../graphics/color.h"
#include "../core/utility.h"


namespace aether {
namespace scene {




class SceneNode
{
public:

    using Shared = std::shared_ptr<SceneNode>;

    math::Vec2f& relativePos()
    {
        return m_relativePosition;
    }

    const math::Vec2f& relativePos() const
    {
        return m_relativePosition;
    }

    math::Vec2f& renderPos()
    {
        return m_renderPosition;
    }

    const math::Vec2f& renderPos() const
    {
        return m_renderPosition;
    }

    int zIndex() const
    {
        return m_zIndex;
    }

    void zIndex(int pzindex)
    {
        m_zIndex = pzindex;
    }

    virtual void render()
    {

    }

    const std::vector<SceneNode*>& children() const
    {
        return m_children;
    }

    const SceneNode* parent() const
    {
        return m_parent;
    }

private:

    SceneNode* m_parent{nullptr};
    graphics::Color m_color;
    std::vector<SceneNode*> m_children;

    int m_zIndex;
    math::Vec2f m_relativePosition;
    math::Vec2f m_renderPosition;


};


class Scene
{
public:
    Scene()
    {
        m_root = new SceneNode;
    }

    void render()
    {
        m_nodesSortedByZindex.clear();
        computeRenderPos(m_root);
        for( auto child : m_nodesSortedByZindex ) {
            child->render();
        }
    }

    void computeRenderPos(SceneNode* node)
    {
        core::insert_sorted(m_nodesSortedByZindex, node, [](auto val,  auto iter) {
            return val->zIndex();
        });
        node->renderPos() = node->parent()->renderPos() + node->relativePos();
        for( auto child : node->children() ) {
            computeRenderPos(child);
        }
    }

private:
    SceneNode* m_root;
    std::vector<SceneNode*> m_nodesSortedByZindex;

};




}
}
