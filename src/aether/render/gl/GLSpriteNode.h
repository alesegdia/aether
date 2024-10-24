#pragma once

#include <nether/nether.h>

#include "aether/render/IBatchedEntity.h"
#include "aether/render/IRenderModule.h"
#include "aether/render/Sprite.h"
#include "aether/render/gl/GLTopology.h"
#include "aether/scene/SceneNode.h"
#include "aether/scene/spritenode.h"

#include "aether/render/gl/GLResources.h"
#include "aether/render/gl/GLShaderProgram.h"

namespace aether::render
{

    class GLSpriteNode : public scene::ISpriteNode, public render::IBatchedEntity
    {
    public:
        GLSpriteNode(core::ModuleObject* o, render::ShaderProgram* shader, render::Texture* texture)
            : ISpriteNode(o)
            , m_shader(shader)
            , m_sprite(o, texture)
        {
            m_topology = std::make_unique<render::GLTopology>();
            m_topology->SetVertexFormat(CreateP3U2VertexFormat());
			m_topology->SetIndices({ 0, 1, 2, 2, 3, 0 });
			m_topology->SetVertices({ -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
									  0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
									  0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
									  -0.5f, 0.5f, 0.0f, 0.0f, 1.0f });
            m_topology->ConfigAndUpload();
        }

		void SetClippingRect(float x, float y, float w, float h) override
		{
			m_sprite.SetClippingRect(x, y, w, h);
		}

		void SetTexture(Texture* texture) override
		{
            m_sprite.SetTexture(texture);
            m_textureConfig = CreateSingleTextureConfig(texture);
		}

        render::ShaderProgram* GetShader() const override
        {
            return m_shader;
        }

        render::TextureConfig GetTextureConfig() const override
        {
            return m_textureConfig;
        }

        glm::mat4x4 GetEntityModel() override
        {
            return GetModel();
        }

        void Draw() override
        {
			auto glshader = ResourceCast(m_shader);
            auto model = GetModel();
			glshader->GetNetherShader()->SetMat4Uniform("model", model);
            m_topology->Draw();
        }

    private:
        Sprite m_sprite;
        render::ShaderProgram* m_shader;
        std::unique_ptr<render::GLTopology> m_topology;
        TextureConfig m_textureConfig;

    };

}
