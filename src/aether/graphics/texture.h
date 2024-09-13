#pragma once

#include "aether/core/ModuleObject.h"
#include "../core/handle.h"
#include "../math/rect.h"

#include "color.h"

namespace aether {
namespace graphics {

    class RenderModule;

    class Texture : public core::ModuleObject
    {
    protected:
        Texture(ModuleObject* o) : ModuleObject(o) {}

    public:
        RenderModule* GetRenderer() const;

        virtual aether::math::Vec2i GetTextureSize(Texture tex) = 0;
    };




    // TODO: move to its own file
class TextureRegion
{
public:
    TextureRegion()
    {

    }

    TextureRegion(const TextureRegion& texreg)
        : m_texture(texreg.m_texture)
        , m_clip(texreg.m_clip)
    {

    }

    TextureRegion(const std::shared_ptr<Texture>& texture)
	    : m_texture(texture)
	    , m_clip(aether::math::Rectf(0.0f, 0.0f, float(texture->GetWidth()), float(texture->GetHeight())))
	{

	}

    TextureRegion(const Texture& texture, float x, float y, float w, float h)
        : m_texture(texture)
        , m_clip(aether::math::Rectf(x, y, w, h))
    {

    }

    TextureRegion(const std::shared_ptr<Texture>& texture, int x, int y, int w, int h)
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
        return *m_texture;
    }

    const aether::math::Rectf& GetClip() const
    {
        return m_clip;
    }

    bool IsValid() const
    {
        return m_texture->IsValid();
    }

private:
    std::shared_ptr<Texture> m_texture;
	aether::math::Rectf m_clip;

};


}
}
