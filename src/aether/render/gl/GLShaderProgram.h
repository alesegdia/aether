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

	private:
		std::unique_ptr<nether::ShaderProgram> m_shader;
	};
}
