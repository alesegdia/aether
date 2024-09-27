#pragma once

#include <nether/nether.h>

#include "aether/scene/spritenode.h"
#include "aether/render/gl/GLSceneNode.h"
#include "aether/render/IRenderModule.h"
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

        }

        void SetClippingRect(float x, float y, float w, float h) override
        {
            m_sprite.SetClippingRect(x, y, w, h);
        }

        render::ShaderProgram* GetShader() override
        {
            return m_shader;
        }

        render::Topology* GetTopology() override
        {
            return nullptr;
        }

    private:
        Sprite m_sprite;
        render::ShaderProgram* m_shader;
    };

}
