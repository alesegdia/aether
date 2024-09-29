#include "src/aether/render/Batch.h"

// Implementation for aether/render/Batch

const std::vector<const IBatchedEntity*>& aether::render::Batch::GetElements() const
{
	return m_elements;
}

void aether::render::Batch::AddElement(const IBatchedEntity* node)
{
	m_elements.push_back(node);
}

void aether::render::Batch::RemoveElement(const IBatchedEntity* node)
{
	m_elements.erase(std::remove(m_elements.begin(), m_elements.end(), node), m_elements.end());
}

aether::render::ShaderProgram* aether::render::Batch::GetShader() const
{
	return m_shader;
}

aether::render::Texture* aether::render::Batch::GetTexture() const
{
	return m_texture;
}

aether::render::Batch::Batch(Texture* texture, render::ShaderProgram* shader) : m_texture(texture)
, m_shader(shader)
{

}
