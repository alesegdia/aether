#pragma once

#include "aether/render/Texture.h"
#include "aether/math/rect.h"
#include <array>

namespace aether::render {

    /**
     * @brief Represents a region of a texture.
     */
    class TextureRegion
    {
    public:
        /**
         * @brief Default constructor.
         */
        TextureRegion();

        /**
         * @brief Constructs a TextureRegion with the entire texture.
         * @param texture Pointer to the texture.
         */
        TextureRegion(Texture* texture);

        /**
         * @brief Constructs a TextureRegion with a specified region.
         * @param texture Pointer to the texture.
         * @param x X coordinate of the region.
         * @param y Y coordinate of the region.
         * @param w Width of the region.
         * @param h Height of the region.
         */
        TextureRegion(Texture* texture, float x, float y, float w, float h);

        /**
         * @brief Constructs a TextureRegion with a specified region.
         * @param texture Pointer to the texture.
         * @param x X coordinate of the region.
         * @param y Y coordinate of the region.
         * @param w Width of the region.
         * @param h Height of the region.
         */
        TextureRegion(Texture* texture, int x, int y, int w, int h);

        /**
         * @brief Sets the clipping region.
         * @param x X coordinate of the region.
         * @param y Y coordinate of the region.
         * @param w Width of the region.
         * @param h Height of the region.
         */
        void SetClip(float x, float y, float w, float h);

        /**
         * @brief Sets the clipping region.
         * @param clip Rectangle defining the clipping region.
         */
        void SetClip(const aether::math::Rectf& clip);

        /**
         * @brief Sets the texture.
         * @param tex Pointer to the texture.
         */
        void SetTexture(Texture* tex);

        /**
         * @brief Gets the texture.
         * @return Pointer to the texture.
         */
        Texture* GetTexture() const;

        /**
         * @brief Gets the clipping region.
         * @return Reference to the clipping rectangle.
         */
        const aether::math::Rectf& GetClip() const;

        /**
         * @brief Gets the UV coordinates.
         * @return Array containing the UV coordinates.
         */
        std::array<float, 4> GetUVs();

    private:
        /**
         * @brief Recomputes the UV coordinates.
         */
        void RecomputeUV();

        Texture* m_texture = nullptr; ///< Pointer to the texture.
        math::Rectf m_clip; ///< Clipping region.
        float m_u0 = 0; ///< U coordinate of the top-left corner.
        float m_v0 = 0; ///< V coordinate of the top-left corner.
        float m_u1 = 0; ///< U coordinate of the bottom-right corner.
        float m_v1 = 0; ///< V coordinate of the bottom-right corner.
        bool m_uvsDirty = true; ///< Flag indicating if the UVs need to be recomputed.
    };

} // namespace aether::render