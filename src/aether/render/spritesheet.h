#pragma once

#include <vector>
#include <memory>
#include "texture.h"

namespace aether::render {


class Spritesheet
{
public:

    typedef std::shared_ptr<Spritesheet> SharedPtr;

    /**
     * @brief Spritesheet
     * @param width in tiles
     * @param height in tiles
     * @param bitmap
     */
    explicit Spritesheet( size_t width, size_t height, Texture texture );

    Spritesheet();

    ~Spritesheet();

    /**
     * @brief retrieves a frame by its index
     * @param num_frame frame index
     * @return the sub bitmap associated to the index
     */
    const TextureRegion* GetFrame( size_t num_frame ) const;

    /**
     * @brief retrieves a frame by its coordinate
     * @param x_frame the x coordinate
     * @param y_frame the y coordinate
     * @return the sub bitmap in specified coordinate
     */
    const TextureRegion* GetFrame( size_t x_frame, size_t y_frame ) const;

    std::vector<const TextureRegion *> getFrames(size_t start, size_t end );
    std::vector<const TextureRegion *> getAllFrames();

    /**
     * @brief resets spritesheet internals to store a new spritesheet data
     * @param width in tiles of the spritesheet
     * @param height in tiles of the spritesheet
     * @param bitmap the whole spritesheet
     */
    void Reset( size_t width, size_t height, Texture texture );
    void Load( size_t width, size_t height, Texture texture );


private:

    /**
     * @brief translates a 2D cartesian coordinate to vector index
     * @param x coordinate
     * @param y coordinate
     * @return the index
     */
    size_t CoordToIndex(size_t x, size_t y ) const;

    std::shared_ptr<Texture> m_texture;
    int m_height{}, m_width{};


};


}
