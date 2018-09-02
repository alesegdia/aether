#pragma once

#include <cstdint>

#include "../math/matrix.h"
#include "../math/vec.h"
#include "../math/rect.h"

namespace aether {
namespace collision {


template <typename InternalDataType>
class GenericTilemap
{
public:

    GenericTilemap(size_t width, size_t height, InternalDataType tile_width, InternalDataType tile_height, std::initializer_list<uint8_t> il);

    GenericTilemap(size_t width, size_t height, InternalDataType tile_width, InternalDataType tile_height);

    void move(math::Rect<InternalDataType>& rect, InternalDataType new_x, InternalDataType new_y);

    void realmove(math::Rect<InternalDataType> &rect, InternalDataType new_x, InternalDataType new_y);


    bool isSolid( size_t x, size_t y );

    math::Vec2i getTile( InternalDataType x, InternalDataType y );

    const math::Matrix2D<uint8_t>& map();

    int tileWidth();

    int tileHeight();


private:

    enum class Direction {
        None, Up, Down, Left, Right
    };

    math::Matrix2D<uint8_t> m_collisionMatrix;
    math::Vec2i m_tileSize;

};

typedef GenericTilemap<int> Tilemap;


}
}
