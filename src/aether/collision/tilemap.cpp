#include "tilemap.h"

namespace aether {
namespace collision {

template <typename InternalDataType>
GenericTilemap<InternalDataType>::GenericTilemap(size_t width, size_t height, InternalDataType tile_width, InternalDataType tile_height, std::initializer_list<uint8_t> il)
    : m_collisionMatrix(width, height, il),
      m_tileSize(tile_width, tile_height)
{

}

template <typename InternalDataType>
GenericTilemap<InternalDataType>::GenericTilemap(size_t width, size_t height, InternalDataType tile_width, InternalDataType tile_height)
    : m_collisionMatrix(width, height),
      m_tileSize(tile_width, tile_height)
{

}

template <typename InternalDataType>
void GenericTilemap<InternalDataType>::move(math::Rect<InternalDataType> &rect, InternalDataType new_x, InternalDataType new_y)
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
        r0 = getTile( x1, y0 );
        r1 = getTile( x1, y1 );
    }
    // moving left
    else if( dx < 0 )
    {
        horizontal = Direction::Left;
        r0 = getTile( x0, y0 );
        r1 = getTile( x0, y1 );
    }

    // moving bottom
    if( dy > 0 )
    {
        vertical = Direction::Down;
        c0 = getTile( x0, y1 );
        c1 = getTile( x1, y1 );
    }
    // moving up
    else if( dy < 0 )
    {
        vertical = Direction::Up;
        c0 = getTile( x0, y0 );
        c1 = getTile( x1, y0 );
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
                }
                else // Direction::Right
                {
                    depth = x1 - (r0.x()) * tileWidth();
                }
            }
        }
        if( depth != 0 )
        {
            dx -= depth;
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
            if( isSolid( x, c0.y() ) )
            {
                if( Direction::Down == vertical )
                {
                    depth = y1 - (c0.y()) * tileHeight();
                }
                else // Direction::Up
                {
                    depth = -((c0.y()+1) * tileHeight() - y0);
                }
            }
        }
        if( depth != 0 )
        {
            dy -= depth;
        }
    }
    else
    {
        dy = 0;
    }

    rect.move(dx, dy);

}

template<typename InternalDataType>
void GenericTilemap<InternalDataType>::realmove(math::Rect<InternalDataType> &rect, InternalDataType new_x, InternalDataType new_y)
{
    move(rect, new_x, rect.y());
    move(rect, rect.x(), new_y);
}

template <typename InternalDataType>
bool GenericTilemap<InternalDataType>::isSolid(size_t x, size_t y)
{
    return m_collisionMatrix.get(x, y) == 1;
}

template <typename InternalDataType>
math::Vec2i GenericTilemap<InternalDataType>::getTile(InternalDataType x, InternalDataType y)
{
    return math::Vec2i( int(x / m_tileSize.x()), int(y / m_tileSize.y()) );
}

template <typename InternalDataType>
const math::Matrix2D<uint8_t> &GenericTilemap<InternalDataType>::map()
{
    return m_collisionMatrix;
}

template <typename InternalDataType>
int GenericTilemap<InternalDataType>::tileWidth()
{
    return m_tileSize.x();
}

template <typename InternalDataType>
int GenericTilemap<InternalDataType>::tileHeight()
{
    return m_tileSize.y();
}


// generate code for int, needed when defining template in .cpp
template class GenericTilemap<int>;



}
}
