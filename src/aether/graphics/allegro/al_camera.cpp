
#include "aether/graphics/allegro/al_camera.h"


namespace aether {
namespace graphics {

	Camera::Camera(const aether::math::Vec2f& viewport /*= aether::math::Vec2f(0, 0)*/) : BaseCamera(viewport)
	{

	}

	void Camera::Bind()
	{
		al_identity_transform(&m_transform);
		al_build_transform(&m_transform,
			GetX() + GetViewport().GetX() / 2.f,
			GetY() + GetViewport().GetY() / 2.f,
			GetScale().GetX(),
			GetScale().GetY(), GetRotation());
		al_use_transform(&m_transform);
	}

}
}
