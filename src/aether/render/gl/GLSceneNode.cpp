#include "GLSceneNode.h"

#include "aether/render/gl/GLRenderModule.h"

namespace aether::render
{

inline GLRenderModule* aether::render::GLSceneNode::GetRenderer()
{
    return (GLRenderModule*)(GetOwner());
}

inline void GLSceneNode::SetTexture(nether::Texture* tex)
{
    if (GetOwner() != nullptr)
    {
        m_texture = tex;
    }
    else
    {
        GetRenderer()->RemoveFromBatch(this);
        m_texture = tex;
        GetRenderer()->AddToBatch(this);
    }
}

inline void GLSceneNode::SetShader(nether::ShaderProgram* sha)
{
    if (GetOwner() != nullptr)
    {
        m_shader = sha;
    }
    else
    {
        GetRenderer()->RemoveFromBatch(this);
        m_shader = sha;
        GetRenderer()->AddToBatch(this);
    }
}


}