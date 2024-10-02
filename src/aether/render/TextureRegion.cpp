#include "TextureRegion.h"

namespace aether::render {

    TextureRegion::TextureRegion()
    {
    }

    TextureRegion::TextureRegion(Texture* texture)
        : m_texture(texture)
    {
        SetClip(math::Rectf(0.0f, 0.0f, float(texture->GetSize().GetX()), float(texture->GetSize().GetY())));
    }

    TextureRegion::TextureRegion(Texture* texture, float x, float y, float w, float h)
        : m_texture(texture)
    {
        SetClip(aether::math::Rectf(x, y, w, h));
    }

    TextureRegion::TextureRegion(Texture* texture, int x, int y, int w, int h)
        : m_texture(texture)
    {
        SetClip(aether::math::Rectf(float(x), float(y), float(w), float(h)));
    }

    void TextureRegion::SetClip(float x, float y, float w, float h)
    {
        SetClip(aether::math::Rectf(x, y, w, h));
    }

    void TextureRegion::SetClip(const aether::math::Rectf& clip)
    {
        m_clip = clip;
        m_uvsDirty = true;
    }

    void TextureRegion::SetTexture(Texture* tex)
    {
        m_texture = tex;
        m_uvsDirty = true;
    }

    Texture* TextureRegion::GetTexture() const
    {
        return m_texture;
    }

    const aether::math::Rectf& TextureRegion::GetClip() const
    {
        return m_clip;
    }

    std::array<float, 4> TextureRegion::GetUVs()
    {
        if (m_uvsDirty)
        {
            RecomputeUV();
            m_uvsDirty = false;
        }
        return { m_u0, m_v0, m_u1, m_v1 };
    }

    void TextureRegion::RecomputeUV()
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

}