#pragma once

#include <string>
#include <memory> // Include memory for std::unique_ptr

#include "aether/render/ShaderProgram.h"
#include "nether/nether.h"

namespace aether::render
{
	class GLShaderProgram : public ShaderProgram
	{
	public:
		GLShaderProgram(ModuleObject* o, const std::string& vspath, const std::string& fspath);

		nether::ShaderProgram* GetNetherShader() const
		{
			return m_shader.get();
		}

		void Use() override;
		void SetBoolUniform(const std::string& name, bool value) override;
		void SetIntUniform(const std::string& name, int value) override;
		void SetFloatUniform(const std::string& name, float value) override;
		void SetMat4Uniform(const std::string& name, const glm::mat4x4& mat) override;

	private:
		std::unique_ptr<nether::ShaderProgram> m_shader;
	};
}
