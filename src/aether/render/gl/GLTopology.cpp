#include "GLTopology.h"

namespace aether::render
{
	void GLTopology::ConfigureVertexAttribs()
	{
		m_vbo.Generate(nether::BufferBindingTarget::ArrayBuffer);
		m_ebo.Generate(nether::BufferBindingTarget::ElementArrayBuffer);
		const auto& components = GetVertexFormat().components;
		for (size_t i = 0; i < components.size(); ++i)
		{
			const auto& component = components[i];
			glEnableVertexAttribArray(static_cast<GLuint>(i));
			glVertexAttribPointer(
				static_cast<GLuint>(i),
				component.size,
				GL_FLOAT,
				GL_FALSE,
				component.stride,
				reinterpret_cast<void*>(static_cast<intptr_t>(component.offset))
			);
		}
	}
}