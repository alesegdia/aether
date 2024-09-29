#pragma once

#include <nether/nether.h>

#include "aether/scene/spritenode.h"
#include "aether/render/gl/GLSceneNode.h"
#include "aether/render/IRenderModule.h"
#include "aether/render/Topology.h"
#include "aether/scene/SceneNode.h"
#include "aether/scene/spritenode.h"
#include "aether/render/IBatchedEntity.h"


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

        render::Topology* GetTopology() const override
        {
            return m_topology.get();
        }

        render::Texture* GetTexture() const override
        {
            return m_sprite.GetRegion()->GetTexture();
        }


    private:
        Sprite m_sprite;
        render::ShaderProgram* m_shader;
        std::unique_ptr<render::Topology> m_topology;

    };

}
