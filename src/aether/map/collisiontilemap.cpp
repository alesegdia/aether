#include "collisiontilemap.h"

namespace aether {
namespace tilemap {

template <typename InternalDataType>
GenericCollisionTileMap<InternalDataType>::GenericCollisionTileMap(TileLayer::Shared tilelayer)
    : m_tileLayer(tilelayer)
{

}

template <typename InternalDataType>
void GenericCollisionTileMap<InternalDataType>::move(math::Rect<InternalDataType> &rect, InternalDataType new_x, InternalDataType new_y, CollisionInfo* ci)
{
    int fixed_col, fixed_row;
    fixed_col = fixed_row = -1;

    math::Vec2i c0, c1, r0, r1;
    int dx, dy, x0, y0, x1, y1;

    Direction horizontal = Direction::None;
    Direction vertical = Direction::None;

    x0 = new_x;
    y0 = new_y;
    x1 = new_x + rect.w();
    y1 = new_y + rect.h();
    dx = x0 - rect.x();
    dy = y0 - rect.y();

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
            if( isSolid( r0.x(), y ) )
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
            bool solid = isSolid( x, c0.y() );
            bool oneway = isOneway( x, c0.y() );

            if( (solid || oneway) && Direction::Down == vertical  )
            {
                depth = y1 - (c0.y()) * tileHeight();
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

template<typename InternalDataType>
typename GenericCollisionTileMap<InternalDataType>::CollisionInfo GenericCollisionTileMap<InternalDataType>::realmove(math::Rect<InternalDataType> &rect, InternalDataType new_x, InternalDataType new_y)
{
    CollisionInfo ci;
    move(rect, new_x, rect.y(), &ci);
    move(rect, rect.x(), new_y, &ci);
    return ci;
}

template <typename InternalDataType>
bool GenericCollisionTileMap<InternalDataType>::isSolid(size_t x, size_t y)
{
    return m_tileLayer->getTileCollisionBehaviour(x, y) == TileCollisionBehaviour::Solid;
}

template <typename InternalDataType>
bool GenericCollisionTileMap<InternalDataType>::isOneway(size_t x, size_t y)
{
    return m_tileLayer->getTileCollisionBehaviour(x, y) == TileCollisionBehaviour::Oneway;
}

template <typename InternalDataType>
math::Vec2i GenericCollisionTileMap<InternalDataType>::getTile(InternalDataType x, InternalDataType y)
{
    return math::Vec2i( int(x / m_tileLayer->tileWidth()), int(y / m_tileLayer->tileHeight()) );
}

template <typename InternalDataType>
int GenericCollisionTileMap<InternalDataType>::tileWidth()
{
    return m_tileLayer->tileWidth();
}

template <typename InternalDataType>
int GenericCollisionTileMap<InternalDataType>::tileHeight()
{
    return m_tileLayer->tileHeight();
}


// generate code for int, needed when defining template in .cpp
template class GenericCollisionTileMap<int>;



}
}
