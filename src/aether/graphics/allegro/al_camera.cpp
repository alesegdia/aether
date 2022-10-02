
#include "aether/graphics/camera.h"


namespace aether {
namespace graphics {


Camera::Camera(const aether::math::Vec2f& viewport)
	: m_viewport(viewport)
{

}

void Camera::Bind()
{
    al_identity_transform(&m_transform);
    al_build_transform(&m_transform,
                       m_position.GetX() + m_viewport.GetX() / 2.f,
                       m_position.GetY() + m_viewport.GetY() / 2.f,
                       m_scale.GetX(),
                       m_scale.GetY(), m_rotation);
	al_use_transform(&m_transform);
}

void Camera::GetPosition(const aether::math::Vec2f& new_position)
{
	m_position = new_position;
	m_position.SetY(-(m_position.GetY()) * m_scale.GetY());
	m_position.SetX(-(m_position.GetX()) * m_scale.GetX());
}

float Camera::GetX()
{
    return - m_position.GetX() / m_scale.GetX();
}

float Camera::GetY()
{
    return - m_position.GetY() / m_scale.GetY();
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

}
}
