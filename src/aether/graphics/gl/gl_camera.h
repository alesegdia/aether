#pragma once

#include "aether/graphics/basecamera.h"
#include "aether/math/vec.h"


namespace aether {
namespace graphics {


class Camera : public BaseCamera
{
public:
	Camera(const aether::math::Vec2f& viewport = aether::math::Vec2f(0, 0));

	void Bind() override;

private:

};

}
}
