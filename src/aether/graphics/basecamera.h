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
	virtual void UnBind() = 0;

    void SetPosition( const aether::math::Vec2f& new_position );

	float GetX();

	float GetY();

    aether::math::Rectf GetBoundary() const;

	void SetPosition( float x, float y );

	void Move( float x, float y );

	void SetScale( float x, float y );

    const aether::math::Vec2f& GetViewport();

    const aether::math::Vec2f& GetScale();

    /// <summary>
    /// Returns the position of the camera with the added shake
    /// THIS NEEDS TO RETURN A COPY BECAUSE THE RETURNED VECTOR IS CREATED NEWLY A
    /// </summary>
    /// <returns></returns>
    aether::math::Vec2f GetPosition();

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


	/*void Update(uint64_t delta)
	{
		//m_deltaRotation = (rand() % 10 - 5) / 50.f;
		//m_deltaPositionX = (rand() % 10) / 50.f;
		//m_deltaPositionY = (rand() % 10) / 50.f;
		//m_deltaZoom = (rand() % 10) / 50.f;
	}*/

protected:

	// cache last (position, scale) if performance issues
    aether::math::Vec2f m_scale = aether::math::Vec2f(1, 1);
    aether::math::Vec2f m_position = aether::math::Vec2f(0,0);
	float m_rotation = 0;

    aether::math::Vec2f m_viewport;

	bool m_shake = false;
	float m_shakeX = 0.0f;
	float m_shakeY = 0.0f;

	// effect on zoom
	float m_wowFX = 10.f;
	float m_deltaZoom = 0;

	// effect on position
	float m_shakeEffect = 10.f;
	float m_deltaPositionX = 0;
	float m_deltaPositionY = 0;

	// effect on rotation
	float m_dazzleFX = 10.f;
	float m_deltaRotation = 0.f;

};


}
}
