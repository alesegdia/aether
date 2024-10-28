#include "aether/render/gl/GLShaderProgram.h"
#include "aether/render/ShaderProgram.h"
#include "nether/nether.h"

namespace aether::render {

    GLShaderProgram::GLShaderProgram(ModuleObject* o, const std::string& vspath, const std::string& fspath)
		: ShaderProgram(o)
	{
		m_shader = std::make_unique<nether::ShaderProgram>();
		m_shader->Load(vspath, fspath);
	}

	void GLShaderProgram::Use()
	{
		m_shader->Use();
	}

    void GLShaderProgram::SetBoolUniform(const std::string& name, bool value)
    {
        m_shader->SetBoolUniform(name, value);
    }

    void GLShaderProgram::SetIntUniform(const std::string& name, int value)
    {
        m_shader->SetIntUniform(name, value);
    }

    void GLShaderProgram::SetFloatUniform(const std::string& name, float value)
    {
        m_shader->SetFloatUniform(name, value);
    }

    void GLShaderProgram::SetMat4Uniform(const std::string& name, const glm::mat4x4& mat)
    {
        m_shader->SetMat4Uniform(name, mat);
    }

}