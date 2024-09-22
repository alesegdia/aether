#pragma once

#include "aether/render/Camera.h"

#include <memory>


namespace aether::render {


	float Camera::GetY()
	{
		return -m_position.GetY() / m_scale.GetY();
	}

	aether::math::Rectf Camera::GetBoundary() const
	{
		return aether::math::Rectf(m_position, m_viewport);
	}

	void Camera::SetPosition(float x, float y)
	{
		m_position.Set(x, y);
	}

	void Camera::Move(float x, float y)
	{
		m_position.Set(m_position.GetX() + x, m_position.GetY() + y);
	}

	void Camera::SetScale(float x, float y)
	{
		m_scale.Set(x, y);
	}

	const aether::math::Vec2f& Camera::GetViewport()
	{
		return m_viewport;
	}

	const aether::math::Vec2f& Camera::GetScale()
	{
		return m_scale;
	}

	aether::math::Vec2f Camera::GetPosition()
	{
		auto pos = m_position;
		pos.SetX(pos.GetX() + m_shakeX);
		pos.SetY(pos.GetY() + m_shakeY);
		return pos;
	}

	void Camera::SetPosition(const aether::math::Vec2f& new_position)
	{
		m_position = new_position;
		m_position.SetY(-(m_position.GetY()) * m_scale.GetY());
		m_position.SetX(-(m_position.GetX()) * m_scale.GetX());
	}

	float Camera::GetX()
	{
		return -m_position.GetX() / m_scale.GetX();
	}

	float Camera::GetRotation() const
	{
		return m_rotation;
	}

}
