#pragma once

#include "aether/render/Texture.h"

namespace aether::render {

    class TextureRegion
    {
    public:
        TextureRegion( Texture* texture)
            : m_texture(texture)
            , m_clip(math::Rectf(0.0f, 0.0f, float(texture->GetSize().GetX()), float(texture->GetSize().GetY())))
        {

        }

        TextureRegion( Texture* texture, float x, float y, float w, float h)
            : m_texture(texture)
            , m_clip(aether::math::Rectf(x, y, w, h))
        {

        }

        TextureRegion( Texture* texture, int x, int y, int w, int h)
            : m_texture(texture)
            , m_clip(aether::math::Rectf(float(x), float(y), float(w), float(h)))
        {

        }

        void SetClip(float x, float y, float w, float h)
        {
            m_clip = aether::math::Rectf(x, y, w, h);
        }

        void SetClip(const aether::math::Rectf& clip)
        {
            m_clip = clip;
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
        Texture* m_texture;
        math::Rectf m_clip;


    };


}
