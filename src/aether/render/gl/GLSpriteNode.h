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
        GLSpriteNode(core::ModuleObject* o, render::ShaderProgram* shader, const glm::fvec2 size)
            : ISpriteNode(o)
            , m_shader(shader)
            , m_sprite(o, nullptr)
        {
            m_renderer = (IRenderModule*)o;
			float szx = size.x;
			float szy = size.y;

            m_topology = std::make_unique<render::GLTopology>();
            m_topology->SetVertexFormat(CreateP3U2VertexFormat());
			m_topology->SetIndices({ 0, 1, 2, 2, 3, 0 });
			m_topology->SetVertices({ -szx, -szy, 0.0f, 0.0f, 0.0f,
									   szx, -szy, 0.0f, 1.0f, 0.0f,
                                       szx,  szy, 0.0f, 1.0f, 1.0f,
									  -szx,  szy, 0.0f, 0.0f, 1.0f });
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
            m_renderer->Refresh(this);
		}

		void SetTextureRegion(TextureRegion* region) override
		{
			m_sprite.SetTexture(region->GetTexture());
			m_sprite.SetClippingRect(region->GetClip().x(), region->GetClip().y(), region->GetClip().w(), region->GetClip().h());
			m_textureConfig = CreateSingleTextureConfig(region->GetTexture());
			m_renderer->Refresh(this);
		}

        render::ShaderProgram* GetShader() const override
        {
            return m_shader;
        }

        render::TextureConfig GetTextureConfig() const override
        {
            return m_textureConfig;
        }

        void Draw() override
        {
			auto glshader = ResourceCast(m_shader);
            auto model = GetModel();
			glshader->SetMat4Uniform("model", model);
            auto uvs = m_sprite.GetRegion()->GetUVs();
            glshader->SetVec2Uniform("uv0", { uvs[0], uvs[1] });
            glshader->SetVec2Uniform("uv1", { uvs[2], uvs[3] });
            m_topology->Draw();
        }

    private:
        Sprite m_sprite;
        render::ShaderProgram* m_shader;
        std::unique_ptr<render::GLTopology> m_topology;
        TextureConfig m_textureConfig;
        IRenderModule* m_renderer;

    };

}
