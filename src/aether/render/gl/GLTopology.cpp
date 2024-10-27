#include "GLTopology.h"

namespace aether::render
{

	void GLTopology::Draw()
	{
		m_vao.Bind();
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_indices.size()), GL_UNSIGNED_INT, nullptr);
		m_vao.Unbind();
	}

	void GLTopology::ConfigAndUpload()
	{
		m_vao.Generate();
		m_vbo.Generate(nether::BufferBindingTarget::ArrayBuffer);
		m_ebo.Generate(nether::BufferBindingTarget::ElementArrayBuffer);

		m_vao.Bind();

		m_vbo.Bind();
		UploadVertices();

		m_ebo.Bind();
		UploadIndices();

		ConfigureVertexAttribs();

		m_vbo.Unbind();
		m_vao.Unbind();
		m_ebo.Unbind();
	}

	void GLTopology::UploadVertices()
	{
		m_vbo.Bind();
		m_vbo.UploadBufferData(m_vertices);
	}

	void GLTopology::UploadIndices()
	{
		m_ebo.Bind();
		m_ebo.UploadBufferData(m_indices);
	}

	void GLTopology::ConfigureVertexAttribs()
	{
		const auto& components = GetVertexFormat().components;
		for (size_t i = 0; i < components.size(); ++i)
		{
			glEnableVertexAttribArray(static_cast<GLuint>(i));

			const auto& component = components[i];
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