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
