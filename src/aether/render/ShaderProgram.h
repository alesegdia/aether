#pragma once

#include <glm/glm.hpp>
#include "aether/core/ModuleObject.h"

namespace aether::render
{
	
	class ShaderProgram : public core::ModuleObject
	{
	public:
		ShaderProgram(core::ModuleObject* owner)
			: core::ModuleObject(owner)
		{

		}

		virtual ~ShaderProgram() = default;

		virtual void Use() = 0;
        virtual void SetBoolUniform(const std::string& name, bool value) = 0;
		virtual void SetIntUniform(const std::string& name, int value) = 0;
		virtual void SetFloatUniform(const std::string& name, float value) = 0;
		virtual void SetMat4Uniform(const std::string& name, const glm::mat4x4& mat) = 0;
		virtual void SetVec2Uniform(const std::string& name, const glm::fvec2& v) = 0;

	};

}
