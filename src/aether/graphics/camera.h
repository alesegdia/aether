#pragma once


#include "../../aether/aether.h"

#include <memory>

class Camera
{
public:

	typedef std::shared_ptr<Camera> SharedPtr;

    Camera( aether::math::Vec2f viewport = aether::math::Vec2f(0, 0) );

	void bind();

    void position( aether::math::Vec2f new_position );

	float x();

	float y();

    aether::math::Rectf boundary() const;

	void position( float x, float y );

	void move( float x, float y );

	void scale( float x, float y );

private:
	ALLEGRO_TRANSFORM m_transform;

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

    FixedScroller( aether::math::Rectf global );

    aether::math::Vec2f scroll( const Camera& cam, aether::math::Vec2f focus ) override;

private:
    aether::math::Rectf m_globalBounds;

};


