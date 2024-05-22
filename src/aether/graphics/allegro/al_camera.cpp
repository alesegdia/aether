
#include "aether/graphics/allegro/al_camera.h"

#include "aether/core/time.h"

namespace aether {
namespace graphics {

	Camera::Camera(const aether::math::Vec2f& viewport)
		: BaseCamera(viewport)
	{

	}

	Camera::Camera(float viewportWidth, float viewportHeight)
		: Camera(aether::math::Vec2f(viewportWidth, viewportHeight))
	{

	}

	void Camera::Bind()
	{
		al_identity_transform(&m_transform);
		al_build_transform(&m_transform,
			GetPosition().GetX() + GetViewport().GetX() / 2.f + m_deltaPositionX,
			GetPosition().GetY() + GetViewport().GetY() / 2.f + m_deltaPositionY,
			GetScale().GetX() + m_deltaZoom,
			GetScale().GetY() + m_deltaZoom, GetRotation() + m_deltaRotation);
		al_use_transform(&m_transform);
	}

}
}
