#pragma once

#include <nether/nether.h>

#include "aether/render/IBatchedEntity.h"
#include "aether/render/IRenderModule.h"
#include "aether/render/Sprite.h"
#include "aether/render/Topology.h"
#include "aether/scene/SceneNode.h"
#include "aether/scene/spritenode.h"

namespace aether::render
{

    class GLSpriteNode : public scene::SceneNode, public scene::ISpriteNode, public render::IBatchedEntity
    {
    public:
        GLSpriteNode(core::ModuleObject* o, render::ShaderProgram* shader, render::Texture* texture)
            : SceneNode(o)
            , m_shader(shader)
            , m_sprite(o, texture)
        {
            m_topology = std::make_unique<render::Topology>();
        }

		void SetClippingRect(float x, float y, float w, float h) override
		{
			m_sprite.SetClippingRect(x, y, w, h);
		}

		void SetTexture(Texture* texture) override
		{
            m_sprite.SetTexture(texture);
		}

        render::ShaderProgram* GetShader() const override
        {
            return m_shader;
        }

        render::Texture* GetTexture() const override
        {
            return m_sprite.GetRegion()->GetTexture();
        }



        void SetTexture(render::Texture* texture) override;


        glm::mat4x4 GetEntityModel() override;


        void Draw() const override;


        bool IsInstanced() const override;

    private:
        Sprite m_sprite;
        render::ShaderProgram* m_shader;
        std::unique_ptr<render::Topology> m_topology;

    };

}
