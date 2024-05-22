#pragma once

#include "aether/graphics/basecamera.h"
#include "aether/math/vec.h"
#include "allegro5/transformations.h"


namespace aether {
namespace graphics {


class Camera : public BaseCamera
{
public:
	Camera(const aether::math::Vec2f& viewport);
	Camera(float viewportWidth, float viewportHeight);

	void Bind() override;


private:
	ALLEGRO_TRANSFORM m_transform{};

};

}
}
