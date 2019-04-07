#pragma once

#include <cstdint>

#include "../math/matrix.h"
#include "../math/vec.h"
#include "../math/rect.h"

#include "tilemap.h"


namespace aether {
namespace tilemap {

struct CollisionInfo
{
    bool collision_x = false;
    bool collision_y = false;
    int x_collision_direction = 0;
    int y_collision_direction = 0;
};

enum class Direction {
    None, Up, Down, Left, Right
};

class GenericCollisionTileMap
{
public:

    GenericCollisionTileMap(TileLayer::Shared tilelayer);
    virtual ~GenericCollisionTileMap();

    CollisionInfo realmove(math::Rect<int> &rect, int new_x, int new_y);

    bool isSolidTile( float x, float y )
    {
        auto pos = getTilePos(x, y);
        return isSolid(pos.x(), pos.y());
    }

protected:
    virtual void move(math::Recti& rect, int new_x, int new_y, CollisionInfo* ci) = 0;

    bool isSolid( size_t x, size_t y );
    bool isOneway( size_t x, size_t y );

    math::Vec2i getTilePos( int x, int y );

    int tileWidth();

    int tileHeight();


private:


    TileLayer::Shared m_tileLayer;

};


class CollisionTilemap : public GenericCollisionTileMap
{
public:
    CollisionTilemap(TileLayer::Shared tilelayer);
    ~CollisionTilemap() override;

private:
    virtual void move(math::Recti& rect, int new_x, int new_y, CollisionInfo* ci) override;

};

//typedef BlockCollisionTileMap CollisionTilemap;


}
}
