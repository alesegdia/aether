
#include "aether/graphics/camera.h"


namespace aether {
namespace graphics {


Camera::Camera(const aether::math::Vec2f& viewport)
	: m_viewport(viewport)
{

}

void Camera::bind()
{
    al_identity_transform(&m_transform);
    al_build_transform(&m_transform,
                       m_position.x() + m_viewport.x() / 2.f,
                       m_position.y() + m_viewport.y() / 2.f,
                       m_scale.x(),
                       m_scale.y(), m_rotation);
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
    return - m_position.x() / m_scale.x();
}

float Camera::y()
{
    return - m_position.y() / m_scale.y();
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


PlatformerScroller::PlatformerScroller(const Camera::SharedPtr &cam,
                                       const math::Rectf &globalBounds,
                                       const math::Vec2f &innerLimits)
    : m_cam(cam),
      m_globalBounds(globalBounds),
      m_innerLimits(innerLimits.x() / cam->scale().x(),
                    innerLimits.y() / cam->scale().y())
{

}

void PlatformerScroller::snapToPlatform(float y)
{
    m_snappedOrdinate = - y * m_cam->scale().y();
}

void PlatformerScroller::focus(float x, float y)
{
    m_focusPos.set(x, y);

    float dx = m_focusPos.x() - m_cam->x();
    float dy = m_focusPos.y() - m_cam->y();

    auto pos = aether::math::Vec2f(x, y);
    float halfViewportX = m_cam->viewport().x() / 2.f / m_cam->scale().x();
    float halfViewportY = m_cam->viewport().y() / 2.f / m_cam->scale().y();
    float xmin = halfViewportX;
    float ymin = halfViewportY;
    float xmax = m_globalBounds.w() - halfViewportX;
    float ymax = m_globalBounds.h() - halfViewportY;
    auto newx = std::max(std::min(pos.x(), xmax), xmin);

    auto newy = std::max(std::min(m_cam->y(), ymax), ymin);
    pos.set(newx, newy);

    float deltaX = m_innerLimits.x() / 2.f;
    if( std::abs(dx) > deltaX )
    {
        deltaX *= (dx > 0) ? -1 : 1;
        pos.set(pos.x() + deltaX, pos.y());
    } else {
        pos.x(m_cam->x());
    }

    auto deltaY = m_innerLimits.y() / 2.f;
    if( std::abs(dy) > deltaY )
    {
        std::cout << dy << std::endl;
        deltaY *= (dy > 0) ? -1 : 1;
        auto toMove = deltaY + dy;
        pos.y(m_cam->y() + toMove);
    }

    m_cam->position(pos);
    m_cam->bind();
}

void PlatformerScroller::update(double delta)
{
    if( m_snappedToPlatform ) {
        double dd = m_snappedOrdinate - m_cam->pos().y();
        auto movY = std::min(std::abs(dd), delta * 0.001);
        if( dd < 0 ) {
            movY *= -1;
        }
        m_cam->move(0, movY);
        if( abs(movY) < delta * 0.0005 ) {
            m_snappedToPlatform = false;
        }
    }

}


}
}
