#pragma once
#include "camera.h"
#include "aether/math/rect.h"
#include "aether/math/vec.h"

namespace aether::graphics
{
	
	class PlatformerScroller
	{
	public:
		PlatformerScroller(const aether::graphics::Camera::SharedPtr& cam,
			const aether::math::Rectf& globalBounds,
			const math::Vec2f& innerLimits);

		void Focus(float x, float y);

		void Update(double delta);

		void SnapToPlatform(float y);

		void SetSnapToPlatform(bool set)
		{
			m_snappedToPlatform = set;
		}

	private:
		Camera::SharedPtr m_cam;
		aether::math::Rectf m_globalBounds;
		aether::math::Vec2f m_innerLimits;
		aether::math::Vec2f m_focusPos;
		float m_snappedOrdinate = 0.f;
		bool m_snappedToPlatform = false;

	};


}
