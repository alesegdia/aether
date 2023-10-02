#include "collisiontilemap.h"

#include <utility>

namespace aether {
namespace tilemap {

GenericCollisionTileMap::GenericCollisionTileMap(TileLayer::Shared tilelayer)
    : m_tileLayer(std::move(tilelayer))
{

}

GenericCollisionTileMap::~GenericCollisionTileMap()
= default;

bool GenericCollisionTileMap::IsSolid(size_t x, size_t y)
{
    return m_tileLayer->GetTileCollisionBehaviour(x, y) == TileCollisionBehaviour::Solid;
}

bool GenericCollisionTileMap::isOneway(size_t x, size_t y)
{
    return m_tileLayer->GetTileCollisionBehaviour(x, y) == TileCollisionBehaviour::Oneway;
}

math::Vec2i GenericCollisionTileMap::GetTilePos(int x, int y)
{
    return math::Vec2i( int(x / m_tileLayer->GetTileWidth()), int(y / m_tileLayer->GetTileHeight()) );
}

int GenericCollisionTileMap::GetTileWidth()
{
    return m_tileLayer->GetTileWidth();
}

int GenericCollisionTileMap::GetTileHeight()
{
    return m_tileLayer->GetTileHeight();
}


CollisionTilemap::CollisionTilemap(TileLayer::Shared tilelayer)
    : GenericCollisionTileMap(std::move(tilelayer))
{

}

CollisionTilemap::~CollisionTilemap()
= default;


void CollisionTilemap::Internal_Move(math::Recti &rect, int new_x, int new_y, CollisionInfo* ci)
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
        r0 = GetTilePos( x1, y0+1 );
        r1 = GetTilePos( x1, y1-1 );
    }
    // moving left
    else if( dx < 0 )
    {
        horizontal = Direction::Left;
        r0 = GetTilePos( x0, y0+1 );
        r1 = GetTilePos( x0, y1-1 );
    }

    // moving bottom
    if( dy > 0 )
    {
        vertical = Direction::Down;
        c0 = GetTilePos( x0+1, y1 );
        c1 = GetTilePos( x1-1, y1 );
    }
    // moving up
    else if( dy < 0 )
    {
        vertical = Direction::Up;
        c0 = GetTilePos( x0+1, y0 );
        c1 = GetTilePos( x1-1, y0 );
    }

    // horizontal movement?
    if( horizontal != Direction::None )
    {
        int depth = 0;
        for( int y = r0.GetY(); y <= r1.GetY(); y++ )
        {
            int xxx = r0.GetX() < 0 ? 0 : r0.GetX();
            int yyy = y < 0 ? 0 : y;
            if( IsSolid( xxx, yyy ) )
            {
                if( Direction::Left == horizontal )
                {
                    depth = -((r0.GetX()+1) * GetTileWidth() - x0);
                    ci->x_collision_direction = -1;
                }
                else // Direction::Right
                {
                    depth = x1 - (r0.GetX()) * GetTileWidth();
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
        for( int x = c0.GetX(); x <= c1.GetX(); x++ )
        {
            size_t tile_x = x < 0 ? 0 : x;
            size_t tile_y = c0.GetY() < 0 ? 0 : c0.GetY();

            bool solid = IsSolid( tile_x, tile_y );
            bool oneway = isOneway( tile_x, tile_y );

            int a = tile_y * int(GetTileHeight());
            int b = int(rect.y2());

            auto diff = a - b; // - rect.h() / 4;

            static constexpr int OneWayPlatformCorrectionThreshold = 10;

            if( (solid || (oneway && diff > -rect.h() - OneWayPlatformCorrectionThreshold)) && Direction::Down == vertical  )
            {
                auto d = y1 - (c0.GetY()) * GetTileHeight();
                depth = d;
                ci->y_collision_direction = 1;
            }
            else if( solid && Direction::Up == vertical )
            {
                depth = -((c0.GetY()+1) * GetTileHeight() - y0);
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

CollisionInfo GenericCollisionTileMap::Move(math::Recti &rect, int new_x, int new_y)
{
    CollisionInfo ci;
    Internal_Move(rect, new_x, rect.y(), &ci);
    Internal_Move(rect, rect.x(), new_y, &ci);
    return ci;
}


}
}
