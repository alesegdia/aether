#pragma once

#include <nether/nether.h>

#include "aether/render/texture.h"
#include "aether/render/IRenderModule.h"


namespace aether::render
{

    /**
     * @class GLTexture
     * @brief Represents a texture in OpenGL.
     */
    class GLTexture : public Texture
    {
    public:
        /**
         * @brief Constructs a GLTexture object.
         * @param owner The IRenderModule that owns this texture.
         * @param tex The nether::Texture object to associate with this GLTexture.
         */
        GLTexture(IRenderModule* owner, std::shared_ptr<nether::Texture> tex);

        /**
         * @brief Gets the size of the texture.
         * @return The size of the texture as a math::Vec2i object.
         */
        math::Vec2i GetSize() const override;

        /**
         * @brief Gets the nether::Texture object associated with this GLTexture.
         * @return The nether::Texture object.
         */
        std::shared_ptr<nether::Texture> GetNetherTexture();

    private:
        std::shared_ptr<nether::Texture> m_texture;
    };

}
