
#include "raylib.h"
#include "aether/graphics/raylib/rl_camera.h"


namespace aether {
namespace graphics {

	Camera::Camera(const aether::math::Vec2f& viewport /*= aether::math::Vec2f(0, 0)*/) : BaseCamera(viewport)
	{
		m_camera.offset = { 0,0 };
	}

	void Camera::Bind()
	{
		m_camera.target = { GetPosition().GetX(), GetPosition().GetY()};
		m_camera.zoom = { GetScale().GetX() };
		m_camera.rotation = GetRotation();
		BeginMode2D(m_camera);
	}

	void Camera::UnBind()
	{
		EndMode2D();
	}

}
}
