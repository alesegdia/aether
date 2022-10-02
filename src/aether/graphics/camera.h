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

	void Bind();

    void GetPosition( const aether::math::Vec2f& new_position );

	float GetX();

	float GetY();

    aether::math::Rectf GetBoundary() const;

	void SetPosition( float x, float y );

	void Move( float x, float y );

	void SetScale( float x, float y );

    const aether::math::Vec2f& GetViewport()
    {
        return m_viewport;
    }

    const aether::math::Vec2f GetScale()
    {
        return m_scale;
    }

    const aether::math::Vec2f& GetPosition()
    {
        return m_position;
    }

private:

    // move this to implementation
	ALLEGRO_TRANSFORM m_transform{};

	// cache last (position, scale) if performance issues
    aether::math::Vec2f m_scale = aether::math::Vec2f(1, 1);
    aether::math::Vec2f m_position = aether::math::Vec2f(0,0);
	float m_rotation = 0;

    aether::math::Vec2f m_viewport;

};


}
}
