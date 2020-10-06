#pragma once


#include "../../aether/aether.h"

#include <memory>


namespace aether {
namespace graphics {


class Camera
{
public:

	typedef std::shared_ptr<Camera> SharedPtr;

    Camera( const aether::math::Vec2f& viewport = aether::math::Vec2f(0, 0) );

	void bind();

    void position( const aether::math::Vec2f& new_position );

	float x();

	float y();

    aether::math::Rectf boundary() const;

	void position( float x, float y );

	void move( float x, float y );

	void scale( float x, float y );

    const aether::math::Vec2f& viewport()
    {
        return m_viewport;
    }

    const aether::math::Vec2f scale()
    {
        return m_scale;
    }

    const aether::math::Vec2f& pos()
    {
        return m_position;
    }

private:
	ALLEGRO_TRANSFORM m_transform{};

	// cache last (position, scale) if performance issues
    aether::math::Vec2f m_scale = aether::math::Vec2f(1, 1);
    aether::math::Vec2f m_position = aether::math::Vec2f(0,0);
	float m_rotation = 0;

    aether::math::Vec2f m_viewport;

};


class PlatformerScroller
{
public:
    PlatformerScroller(const Camera::SharedPtr& cam,
                        const aether::math::Rectf& globalBounds,
                        const math::Vec2f &innerLimits);

    void focus(float x, float y);

    void update(double delta);

    void snapToPlatform(float y);

    void setSnapToPlatform(bool set)
    {
        m_snappedToPlatform = set;
    }

private:
    Camera::SharedPtr m_cam;
    aether::math::Rectf m_globalBounds;
    aether::math::Vec2f m_innerLimits;
    aether::math::Vec2f m_focusPos;
    float m_snappedOrdinate = 0.f;
    bool m_snappedToPlatform = false;

};


}
}
