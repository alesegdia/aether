#pragma once



#include <memory>

#include "aether/math/rect.h"
#include "aether/math/vec.h"
#include "aether/core/time.h"


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

    void SetPosition( const aether::math::Vec2f& new_position );

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

	void EnableShake()
	{
		m_shake = true;
	}

	void DisableShake()
	{
		m_shake = false;
	}

	void Update()
	{
		if (m_shake)
		{
			auto time = aether::core::get_time();
			m_shakeX = sin(time) * 10;
		}
		else
		{
			m_shakeX = 0;
			m_shakeY = 0;
		}
	}


private:

	// cache last (position, scale) if performance issues
    aether::math::Vec2f m_scale = aether::math::Vec2f(1, 1);
    aether::math::Vec2f m_position = aether::math::Vec2f(0,0);
	float m_rotation = 0;

    aether::math::Vec2f m_viewport;

	bool m_shake = false;
	float m_shakeX = 0.0f;
	float m_shakeY = 0.0f;

};


}
}
