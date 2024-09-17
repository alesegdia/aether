#pragma once

#include "aether/render/Camera.h"
#include "aether/math/rect.h"
#include "aether/math/vec.h"

namespace aether::render {

	class TopDownMapScroller
	{
	public:
		void Setup(const aether::render::Camera::SharedPtr& cam, const aether::math::Rectf& globalBounds);

		void Focus(float x, float y);

	private:
		Camera::SharedPtr m_cam;
		aether::math::Rectf m_globalBounds;
		aether::math::Vec2f m_focusPos;
		bool m_pixelPerfect = true;

	};

}
