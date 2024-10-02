#include "aether/render/Batch.h"
#include "aether/render/IBatchedEntity.h"
#include "aether/render/ShaderProgram.h"
#include "aether/render/Texture.h"
#include <algorithm>

namespace aether::render {

    const std::vector<const IBatchedEntity*>& Batch::GetElements() const
    {
        return m_elements;
    }

    void Batch::AddElement(const IBatchedEntity* node)
    {
        m_elements.push_back(node);
    }

    void Batch::RemoveElement(const IBatchedEntity* node)
    {
        m_elements.erase(std::remove(m_elements.begin(), m_elements.end(), node), m_elements.end());
    }

    ShaderProgram* Batch::GetShader() const
    {
        return m_shader;
    }

    Texture* Batch::GetTexture() const
    {
        return m_texture;
    }

    Batch::Batch(Texture* texture, ShaderProgram* shader) : m_texture(texture), m_shader(shader)
    {
    }

}