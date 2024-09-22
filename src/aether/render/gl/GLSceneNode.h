#pragma once

#include <nether/nether.h>

#include "aether/scene/SceneNode.h"
#include "aether/render/TextureRegion.h"
#include "aether/core/ModuleObject.h"

namespace aether::render {

    class GLRenderModule;

    class GLSceneNode : public scene::SceneNode
    {
    public:
        GLSceneNode(ModuleObject* o) : scene::SceneNode(o) {}

        virtual ~GLSceneNode()
        {

        }

        GLRenderModule* GetRenderer();

        void SetTexture(nether::Texture* tex);

        void SetShader(nether::ShaderProgram* sha);

        void SetVertices(nether::Vertices* verts)
        {
            m_vertices = verts;
        }

        nether::ShaderProgram* GetShader() const
        {
            return m_shader;
        }

        nether::Texture* GetTexture() const
        {
            return m_texture;
        }

    private:
        nether::Texture* m_texture;
        nether::ShaderProgram* m_shader;
        nether::Vertices* m_vertices;



    };


}
