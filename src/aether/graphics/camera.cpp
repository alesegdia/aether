
#include "camera.h"


namespace aether {
namespace graphics {


Camera::Camera(const aether::math::Vec2f& viewport)
	: m_viewport(viewport)
{

}

void Camera::bind()
{
	al_identity_transform(&m_transform);
	al_build_transform(&m_transform, m_position.x(), m_position.y(), m_scale.x(), m_scale.y(), m_rotation);
	al_use_transform(&m_transform);
}

void Camera::position(const aether::math::Vec2f& new_position)
{
	m_position = new_position;
	m_position.y(-(m_position.y()) * m_scale.y());
	m_position.x(-(m_position.x()) * m_scale.x());
}

float Camera::x()
{
	return m_position.x();
}

float Camera::y()
{
	return m_position.y();
}

aether::math::Rectf Camera::boundary() const
{
    return aether::math::Rectf(m_position, m_viewport);
}

void Camera::position(float x, float y)
{
	m_position.set(x, y);
}

void Camera::move(float x, float y)
{
	m_position.set(m_position.x() + x, m_position.y() + y);
}

void Camera::scale(float x, float y)
{
	m_scale.set(x, y);
}


void Scroller::operator()(Camera &cam, float x, float y)
{
    cam.position(scroll(cam, aether::math::Vec2f(x, y)));
}


Scroller::~Scroller()
= default;


FixedScroller::FixedScroller(const aether::math::Rectf& global)
	: m_globalBounds(global) {}


aether::math::Vec2f FixedScroller::scroll(const Camera &cam, aether::math::Vec2f focus)
{
    aether::math::Rectf cam_boundary = cam.boundary();
	cam_boundary.position( focus );
	return clamp(cam_boundary, m_globalBounds).min();
}


}
}
