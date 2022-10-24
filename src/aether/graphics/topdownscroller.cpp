#include "aether/graphics/topdownscroller.h"

namespace aether::graphics
{

	void TopDownMapScroller::Focus(float x, float y)
	{
		m_focusPos.Set(x, y);

		float dx = m_focusPos.GetX() - m_cam->GetX();
		float dy = m_focusPos.GetY() - m_cam->GetY();

		auto pos = aether::math::Vec2f(x, y);
		float halfViewportX = m_cam->GetViewport().GetX() / 2.f / m_cam->GetScale().GetX();
		float halfViewportY = m_cam->GetViewport().GetY() / 2.f / m_cam->GetScale().GetY();
		float xmin = halfViewportX;
		float ymin = halfViewportY;
		float xmax = m_globalBounds.w() - halfViewportX;
		float ymax = m_globalBounds.h() - halfViewportY;
		auto newx = std::max(std::min(pos.GetX(), xmax), xmin);
		auto newy = std::max(std::min(pos.GetY(), ymax), ymin);
		pos.Set(floor(newx), floor(newy));

		m_cam->SetPosition(pos);
		m_cam->Bind();
	}

	void TopDownMapScroller::Setup(const aether::graphics::Camera::SharedPtr& cam, const aether::math::Rectf& globalBounds)
	{
		m_cam = cam;
		m_globalBounds = globalBounds;
	}

}