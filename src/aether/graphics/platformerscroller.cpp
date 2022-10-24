
#include "aether/graphics/platformerscroller.h"

namespace aether::graphics
{


	PlatformerScroller::PlatformerScroller(const Camera::SharedPtr& cam,
		const math::Rectf& globalBounds,
		const math::Vec2f& innerLimits)
		: m_cam(cam),
		m_globalBounds(globalBounds),
		m_innerLimits(innerLimits.GetX() / cam->GetScale().GetX(),
			innerLimits.GetY() / cam->GetScale().GetY())
	{

	}

	void PlatformerScroller::SnapToPlatform(float y)
	{
		m_snappedOrdinate = -y * m_cam->GetScale().GetY();
	}

	void PlatformerScroller::Focus(float x, float y)
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

		auto newy = std::max(std::min(m_cam->GetY(), ymax), ymin);
		pos.Set(newx, newy);

		float deltaX = m_innerLimits.GetX() / 2.f;
		if (std::abs(dx) > deltaX)
		{
			deltaX *= (dx > 0) ? -1 : 1;
			pos.Set(pos.GetX() + deltaX, pos.GetY());
		}
		else
		{
			pos.SetX(m_cam->GetX());
		}

		auto deltaY = m_innerLimits.GetY() / 2.f;
		if (std::abs(dy) > deltaY)
		{
			std::cout << dy << std::endl;
			deltaY *= (dy > 0) ? -1 : 1;
			auto toMove = deltaY + dy;
			pos.SetY(m_cam->GetY() + toMove);
		}

		m_cam->SetPosition(pos);
		m_cam->Bind();
	}

	void PlatformerScroller::Update(double delta)
	{
		if (m_snappedToPlatform) {
			double dd = m_snappedOrdinate - m_cam->GetPosition().GetY();
			auto movY = std::min(std::abs(dd), delta * 0.001);
			if (dd < 0) {
				movY *= -1;
			}
			m_cam->Move(0, movY);
			if (abs(movY) < delta * 0.0005) {
				m_snappedToPlatform = false;
			}
		}

	}


}