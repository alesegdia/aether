#include "aether/render/gl/GLShaderProgram.h"
#include "aether/render/ShaderProgram.h"
#include "nether/nether.h"

namespace aether::render {
	GLShaderProgram::GLShaderProgram(ModuleObject* o, const std::string& vspath, const std::string& fspath)
		: ShaderProgram(o) {
		m_shader = std::make_unique<nether::ShaderProgram>();
		m_shader->Load(vspath, fspath);
	}
}