#pragma once

#include "../core/handle.h"
#include "../math/rect.h"

#include "color.h"

namespace aether {
namespace graphics {


class Texture : public core::Handle
{
public:

    Texture()
        : core::Handle ()
    {

    }

    int height() const;
    int width() const;
    void destroy();
    void draw(float x, float y) const;
    void draw(float x, float y,
              float rx, float ry, float rw, float rh,
              aether::graphics::Color color = aether::graphics::Color(1.f,1.f,1.f),
              bool xflip=false, bool yflip=false,
              float centerx=0.0f, float centery=0.0f, float angle=0.0f, float xscale=1.0f, float yscale=1.0f) const;
	void draw(float x, float y, float alpha) const;
    void load(const char* path);


    // temporary here, was protected
    Texture(int h)
    {
        handle(h);
    }


protected:


};


class TextureRegion
{
public:
    TextureRegion(const TextureRegion& texreg)
        : m_texture(texreg.m_texture)
        , m_clip(texreg.m_clip)
    {

    }

    TextureRegion(const Texture& texture)
	    : m_texture(texture)
	    , m_clip(aether::math::Rectf(0.0f, 0.0f, float(texture.width()), float(texture.height())))
	{

	}

	TextureRegion(const Texture& texture, float x, float y, float w, float h)
	    : m_texture(texture)
	    , m_clip(aether::math::Rectf(x, y, w, h))
	{

	}

	void setRegion(float x, float y, float w, float h)
	{
		m_clip = aether::math::Rectf(x, y, w, h);
	}

    void draw(float x, float y, bool xflip = false, bool yflip = false) const
	{
        m_texture.draw(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(), graphics::Color(1.0f, 1.0f, 1.0f), xflip, yflip);
	}

    void draw(float x, float y, float cx, float cy, float angle) const
    {
        m_texture.draw(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(),
                       Color(1.f,1.f,1.f),
                       false, false, cx, cy, angle);
    }

    void draw(float x, float y, float xscale, float yscale) const
    {
        m_texture.draw(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(), aether::graphics::Color(1.0f, 1.0f, 1.0f),
            false, false, 0.0f, 0.0f, 0.0f, xscale, yscale);
    }

    const Texture& texture() const
    {
        return m_texture;
    }

    const aether::math::Rectf& clip() const
    {
        return m_clip;
    }

private:
    Texture m_texture;
	aether::math::Rectf m_clip;

};


}
}
