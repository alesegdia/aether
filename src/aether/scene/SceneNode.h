#pragma once

#include <memory>
#include <vector>

#include "aether/math/vec.h"
#include "aether/render/Color.h"


namespace aether::scene {


class SceneNode : public std::enable_shared_from_this<SceneNode>
{
public:

    SceneNode() = default;

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
    /// Gets the depth render order, only useful for 2D
    /// </summary>
    /// <returns></returns>
    int GetZIndex() const;

    /// <summary>
    /// Sets the depth render order, only useful for 2D
    /// </summary>
    /// <param name="pzindex"></param>
    void SetZIndex(int pzindex);

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
    render::Color m_color = render::Color(1.0f, 1.0f, 1.0f);
    std::vector<SceneNode::Shared> m_children;
    bool m_dirty;

    int m_zIndex;
    math::Vec2f m_relativePosition;
    math::Vec2f m_renderPosition;
    math::Vec2f m_center;
    float m_angle = 0.0f;


};


}
