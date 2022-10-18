#pragma once



#include <memory>

#include "aether/math/rect.h"
#include "aether/math/vec.h"


namespace aether {
namespace graphics {


class BaseCamera
{
public:

	typedef std::shared_ptr<BaseCamera> SharedPtr;

    BaseCamera( const aether::math::Vec2f& viewport = aether::math::Vec2f(0, 0) )
	    : m_viewport(viewport)
	{
	    
    }

	virtual void Bind() = 0;

    void GetPosition( const aether::math::Vec2f& new_position );

	float GetX();

	float GetY();

    aether::math::Rectf GetBoundary() const;

	void SetPosition( float x, float y );

	void Move( float x, float y );

	void SetScale( float x, float y );

    const aether::math::Vec2f& GetViewport();

    const aether::math::Vec2f GetScale();

    const aether::math::Vec2f& GetPosition();

	float GetRotation() const;

private:

	// cache last (position, scale) if performance issues
    aether::math::Vec2f m_scale = aether::math::Vec2f(1, 1);
    aether::math::Vec2f m_position = aether::math::Vec2f(0,0);
	float m_rotation = 0;

    aether::math::Vec2f m_viewport;

};


}
}
