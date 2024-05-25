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

    int GetHeight() const;
    int GetWidth() const;
    void Destroy();
    void Draw(float x, float y) const;
    void Draw(float x, float y,
        float rx, float ry, float rw, float rh,
        aether::graphics::Color color = aether::graphics::Color(1.f, 1.f, 1.f),
        bool xflip = false, bool yflip = false,
        float centerx = 0.0f, float centery = 0.0f, float angle = 0.0f, float xscale = 1.0f, float yscale = 1.0f) const;
    void DrawScaledCentered(float x, float y,
        float rx, float ry, float rw, float rh,
        aether::graphics::Color color = aether::graphics::Color(1.f, 1.f, 1.f),
        bool xflip = false, bool yflip = false,
        float centerx = 0.0f, float centery = 0.0f, float angle = 0.0f, float xscale = 1.0f, float yscale = 1.0f) const;
    void Draw(float x, float y, float alpha) const;
    void DrawTinted(float x, float y, float sx, float sy, float sw, float sh, const aether::graphics::Color& color) const;
    void Load(const char* path);


    // temporary here, was protected
    Texture(int h)
    {
        SetHandle(h);
    }


protected:


};


    // TODO: move to its own file
class TextureRegion
{
public:
    static TextureRegion Create(std::string path)
    {
        aether::graphics::Texture t;
        t.Load(path.c_str());
        return TextureRegion(t);
    }

    TextureRegion()
    {

    }

    TextureRegion(const TextureRegion& texreg)
        : m_texture(texreg.m_texture)
        , m_clip(texreg.m_clip)
    {

    }

    TextureRegion(const Texture& texture)
	    : m_texture(texture)
	    , m_clip(aether::math::Rectf(0.0f, 0.0f, float(texture.GetWidth()), float(texture.GetHeight())))
	{

	}

    TextureRegion(const Texture& texture, float x, float y, float w, float h)
        : m_texture(texture)
        , m_clip(aether::math::Rectf(x, y, w, h))
    {

    }

    TextureRegion(const Texture& texture, int x, int y, int w, int h)
        : m_texture(texture)
        , m_clip(aether::math::Rectf(float(x), float(y), float(w), float(h)))
    {

    }

    void SetRegion(float x, float y, float w, float h)
	{
		m_clip = aether::math::Rectf(x, y, w, h);
	}

    void Draw(float x, float y, bool xflip = false, bool yflip = false) const
	{
        m_texture.Draw(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(), graphics::Color(1.0f, 1.0f, 1.0f), xflip, yflip);
	}

    void Draw(float x, float y, float cx, float cy, float angle) const
    {
        m_texture.Draw(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(),
                       Color(1.f,1.f,1.f),
                       false, false, cx, cy, angle);
    }

    void Draw(float x, float y, float xscale, float yscale) const
    {
        m_texture.Draw(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(), aether::graphics::Color(1.0f, 1.0f, 1.0f),
            false, false, 0.0f, 0.0f, 0.0f, xscale, yscale);
    }

    void DrawRotatedScaled(float x, float y, float xscale, float yscale, float rotation) const
    {
        m_texture.Draw(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(), aether::graphics::Color(1.0f, 1.0f, 1.0f),
            false, false, 0.0f, 0.0f, rotation, xscale, yscale);
    }

    void DrawRotatedScaledCentered(float x, float y, float xscale, float yscale, float rotation) const
    {
        m_texture.DrawScaledCentered(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(), aether::graphics::Color(1.0f, 1.0f, 1.0f),
            false, false, 0.0f, 0.0f, rotation, xscale, yscale);
    }

    void Draw(float x, float y, const aether::graphics::Color& color) const
    {
        m_texture.DrawTinted(x, y, m_clip.x(), m_clip.y(), m_clip.w(), m_clip.h(), color);
    }

    const Texture& GetTexture() const
    {
        return m_texture;
    }

    const aether::math::Rectf& GetClip() const
    {
        return m_clip;
    }

    bool IsValid() const
    {
        return m_texture.IsValid();
    }

private:
    Texture m_texture;
	aether::math::Rectf m_clip;

};


}
}
