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

private:
	ALLEGRO_TRANSFORM m_transform{};

	// cache last (position, scale) if performance issues
    aether::math::Vec2f m_scale = aether::math::Vec2f(1, 1);
    aether::math::Vec2f m_position = aether::math::Vec2f(0,0);
	float m_rotation = 0;

    aether::math::Vec2f m_viewport;

};


class Scroller
{
public:
	virtual ~Scroller() = 0 ;

	void operator()(Camera& cam, float x, float y);

    virtual aether::math::Vec2f scroll( const Camera& cam, aether::math::Vec2f focus ) = 0 ;

};


class FixedScroller : public Scroller
{
public:

    FixedScroller( const aether::math::Rectf& global );

    aether::math::Vec2f scroll( const Camera& cam, aether::math::Vec2f focus ) override;

private:
    aether::math::Rectf m_globalBounds;

};

class PlatformerScroller
{
public:
    PlatformerScroller(std::shared_ptr<Camera> cam, const aether::math::Rectf& mapBounds );

    void focus(float x, float y);

private:
    Camera::SharedPtr m_cam;
    aether::math::Rectf m_mapBounds;

};


}
}
