#pragma once

#include "aether/core/ModuleObject.h"
#include "../core/handle.h"
#include "../math/rect.h"

#include "color.h"

namespace aether::render {

    class RenderModule;

    class Texture : public core::ModuleObject
    {
    protected:
        Texture(ModuleObject* o) : ModuleObject(o) {}

    public:
        RenderModule* GetRenderer() const;

        virtual math::Vec2i GetSize() const = 0;
    };




    // TODO: move to its own file
class TextureRegion
{
private:
    std::shared_ptr<Texture> m_texture;
    math::Rectf m_clip;

public:
    TextureRegion(const std::shared_ptr<Texture>& texture)
	    : m_texture(texture)
	    , m_clip(math::Rectf(0.0f, 0.0f, float(texture->GetSize().GetX()), float(texture->GetSize().GetY())))
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

private:

};


}
}
