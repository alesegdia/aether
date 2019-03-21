#include "collisiontilemap.h"

namespace aether {
namespace tilemap {

GenericCollisionTileMap::GenericCollisionTileMap(TileLayer::Shared tilelayer)
    : m_tileLayer(tilelayer)
{

}

GenericCollisionTileMap::~GenericCollisionTileMap()
{

}

bool GenericCollisionTileMap::isSolid(size_t x, size_t y)
{
    return m_tileLayer->getTileCollisionBehaviour(x, y) == TileCollisionBehaviour::Solid;
}

bool GenericCollisionTileMap::isOneway(size_t x, size_t y)
{
    return m_tileLayer->getTileCollisionBehaviour(x, y) == TileCollisionBehaviour::Oneway;
}

math::Vec2i GenericCollisionTileMap::getTile(int x, int y)
{
    return math::Vec2i( int(x / m_tileLayer->tileWidth()), int(y / m_tileLayer->tileHeight()) );
}

int GenericCollisionTileMap::tileWidth()
{
    return m_tileLayer->tileWidth();
}

int GenericCollisionTileMap::tileHeight()
{
    return m_tileLayer->tileHeight();
}


BlockCollisionTileMap::BlockCollisionTileMap(TileLayer::Shared tilelayer)
    : GenericCollisionTileMap(tilelayer)
{

}

BlockCollisionTileMap::~BlockCollisionTileMap()
{

}


void BlockCollisionTileMap::move(math::Recti &rect, int new_x, int new_y, CollisionInfo* ci)
{
    int fixed_col, fixed_row;
    fixed_col = fixed_row = -1;

    math::Vec2i c0, c1, r0, r1;
    int dx, dy, x0, y0, x1, y1;

    Direction horizontal = Direction::None;
    Direction vertical = Direction::None;

    int rw2, rh2;
    rw2 = rect.w() / 2;
    rh2 = rect.h() / 2;

    dx = new_x - rect.x();
    dy = new_y - rect.y();

    x0 = new_x - rw2;
    y0 = new_y - rh2;
    x1 = x0 + rect.w();
    y1 = y0 + rect.h();

    // moving right
    if( dx > 0 )
    {
        horizontal = Direction::Right;
        r0 = getTile( x1, y0+1 );
        r1 = getTile( x1, y1-1 );
    }
    // moving left
    else if( dx < 0 )
    {
        horizontal = Direction::Left;
        r0 = getTile( x0, y0+1 );
        r1 = getTile( x0, y1-1 );
    }

    // moving bottom
    if( dy > 0 )
    {
        vertical = Direction::Down;
        c0 = getTile( x0+1, y1 );
        c1 = getTile( x1-1, y1 );
    }
    // moving up
    else if( dy < 0 )
    {
        vertical = Direction::Up;
        c0 = getTile( x0+1, y0 );
        c1 = getTile( x1-1, y0 );
    }

    // horizontal movement?
    if( horizontal != Direction::None )
    {
        int depth = 0;
        for( int y = r0.y(); y <= r1.y(); y++ )
        {
            int xxx = r0.x() < 0 ? 0 : r0.x();
            int yyy = y < 0 ? 0 : y;
            if( isSolid( xxx, yyy ) )
            {
                if( Direction::Left == horizontal )
                {
                    depth = -((r0.x()+1) * tileWidth() - x0);
                    ci->x_collision_direction = -1;
                }
                else // Direction::Right
                {
                    depth = x1 - (r0.x()) * tileWidth();
                    ci->x_collision_direction = 1;
                }
            }
        }
        if( depth != 0 )
        {
            dx -= depth;
            ci->collision_x = true;
        }
    }
    else
    {
        dx = 0;
    }

    // vertical movement?
    if( vertical != Direction::None )
    {
        int depth = 0;
        for( int x = c0.x(); x <= c1.x(); x++ )
        {
            size_t tile_x = x < 0 ? 0 : x;
            size_t tile_y = c0.y() < 0 ? 0 : c0.y();

            bool solid = isSolid( tile_x, tile_y );
            bool oneway = isOneway( tile_x, tile_y );

            int a = tile_y * tileHeight();
            int b = int(rect.y2());

            auto diff = a - b; // - rect.h() / 4;
            std::cout << a << ", " << b << ", " << diff << std::endl;

            static constexpr int OneWayPlatformCorrectionThreshold = 10;

            if( (solid || (oneway && diff > -rect.h() - OneWayPlatformCorrectionThreshold)) && Direction::Down == vertical  )
            {
                auto d = y1 - (c0.y()) * tileHeight();
                depth = d;
                ci->y_collision_direction = 1;
            }
            else if( solid && Direction::Up == vertical )
            {
                depth = -((c0.y()+1) * tileHeight() - y0);
                ci->y_collision_direction = -1;
            }
        }
        if( depth != 0 )
        {
            dy -= depth;
            ci->collision_y = true;
        }
    }
    else
    {
        dy = 0;
    }

    rect.move(dx, dy);

}

CollisionInfo GenericCollisionTileMap::realmove(math::Recti &rect, int new_x, int new_y)
{
    CollisionInfo ci;
    move(rect, new_x, rect.y(), &ci);
    move(rect, rect.x(), new_y, &ci);
    return ci;
}


}
}
