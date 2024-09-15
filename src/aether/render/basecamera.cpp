#pragma once


#include "../../aether/aether.h"

#include <memory>


namespace aether::render {


	float BaseCamera::GetY()
	{
		return -m_position.GetY() / m_scale.GetY();
	}

	aether::math::Rectf BaseCamera::GetBoundary() const
	{
		return aether::math::Rectf(m_position, m_viewport);
	}

	void BaseCamera::SetPosition(float x, float y)
	{
		m_position.Set(x, y);
	}

	void BaseCamera::Move(float x, float y)
	{
		m_position.Set(m_position.GetX() + x, m_position.GetY() + y);
	}

	void BaseCamera::SetScale(float x, float y)
	{
		m_scale.Set(x, y);
	}

	const aether::math::Vec2f& BaseCamera::GetViewport()
	{
		return m_viewport;
	}

	const aether::math::Vec2f& BaseCamera::GetScale()
	{
		return m_scale;
	}

	aether::math::Vec2f BaseCamera::GetPosition()
	{
		auto pos = m_position;
		pos.SetX(pos.GetX() + m_shakeX);
		pos.SetY(pos.GetY() + m_shakeY);
		return pos;
	}

	void BaseCamera::SetPosition(const aether::math::Vec2f& new_position)
	{
		m_position = new_position;
		m_position.SetY(-(m_position.GetY()) * m_scale.GetY());
		m_position.SetX(-(m_position.GetX()) * m_scale.GetX());
	}

	float BaseCamera::GetX()
	{
		return -m_position.GetX() / m_scale.GetX();
	}

	float BaseCamera::GetRotation() const
	{
		return m_rotation;
	}

}
