#pragma once

#include "aether/render/Texture.h"
#include "aether/math/rect.h"

namespace aether::render {

    class TextureRegion
    {
    public:
        TextureRegion()
        {

        }

        TextureRegion( Texture* texture )
            : m_texture(texture)
        {
            SetClip(math::Rectf(0.0f, 0.0f, float(texture->GetSize().GetX()), float(texture->GetSize().GetY())));
        }

        TextureRegion( Texture* texture, float x, float y, float w, float h)
            : m_texture(texture)
        {
            SetClip(aether::math::Rectf(x, y, w, h));
        }

        TextureRegion( Texture* texture, int x, int y, int w, int h)
            : m_texture(texture)
        {
            SetClip(aether::math::Rectf(float(x), float(y), float(w), float(h)));
        }

        void SetClip(float x, float y, float w, float h)
        {
            SetClip(aether::math::Rectf(x, y, w, h));
        }

        void SetClip(const aether::math::Rectf& clip)
        {
            m_clip = clip;
            RecomputeUV();
        }

        void SetTexture(Texture* tex)
        {
            m_texture = tex;
        }

        Texture* GetTexture() const
        {
            return m_texture;
        }

        const aether::math::Rectf& GetClip() const
        {
            return m_clip;
        }

    private:
        void RecomputeUV()
        {
            auto size = m_texture->GetSize();
            auto tx = size.GetX();
            auto ty = size.GetY();
            auto cx = m_clip.x();
            auto cy = m_clip.y();
            auto cw = m_clip.w();
            auto ch = m_clip.h();

            m_u0 = cx / tx;
            m_v0 = cy / ty;
            m_u1 = m_u0 + cw / tx;
            m_v1 = m_v0 + ch / ty;
        }
        
        Texture* m_texture;
        math::Rectf m_clip;
        float m_u0 = 0;
        float m_v0 = 0;
        float m_u1 = 0;
        float m_v1 = 0;


    };


}
