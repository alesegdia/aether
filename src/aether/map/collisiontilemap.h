#pragma once

#include <cstdint>

#include "../math/matrix.h"
#include "../math/vec.h"
#include "../math/rect.h"

#include "tilemap.h"


namespace aether {
namespace tilemap {


template <typename InternalDataType>
class GenericCollisionTileMap
{
public:

    struct CollisionInfo
    {
        bool collision_x = false;
        bool collision_y = false;
        int x_collision_direction = 0;
        int y_collision_direction = 0;
    };

    GenericCollisionTileMap(TileLayer::Shared tilelayer);

    void move(math::Rect<InternalDataType>& rect, InternalDataType new_x, InternalDataType new_y, CollisionInfo* ci);

    CollisionInfo realmove(math::Rect<InternalDataType> &rect, InternalDataType new_x, InternalDataType new_y);

    bool isSolid( size_t x, size_t y );

    math::Vec2i getTile( InternalDataType x, InternalDataType y );

    int tileWidth();

    int tileHeight();


private:

    enum class Direction {
        None, Up, Down, Left, Right
    };

    TileLayer::Shared m_tileLayer;

};

typedef GenericCollisionTileMap<int> CollisionTilemap;


}
}
