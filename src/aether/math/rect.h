#pragma once

#include "vec.h"

namespace aether {
namespace math {


template <typename T>
class Rect
{
public:
    Rect( T x, T y, T w, T h )
        : m_position(x, y),
          m_size(w, h)
    {
        computeCenter();
    }

    Rect( const Vec2<T> pos, const Vec2<T> size )
        : m_position(pos), m_size(size)
    {
        computeCenter();
    }

    Rect( const Rect<T>& other )
        : m_position(other.x(), other.y()), m_size(other.w(), other.h())
    {
        computeCenter();
    }

    Rect()
    {

    }

    Vec2<T> min() const
    {
        return m_position;
    }

    Vec2<T> max() const
    {
        return m_position + m_size;
    }

    void position( Vec2<T> new_pos )
    {
        m_position = new_pos;
        computeCenter();
    }

    void position( float x, float y )
    {
        m_position.set(x, y);
        computeCenter();
    }

    const Vec2<T>& position() const
    {
        return m_position;
    }
    
    const Vec2<T>& center() const
    {
        return m_center;
    }

    void x( T new_x )
    {
        m_position.x(new_x);
        computeCenter();
    }

    void y( T new_y )
    {
        m_position.y(new_y);
        computeCenter();
    }

    T x() const
    {
        return m_position.x();
    }

    T y() const
    {
        return m_position.y();
    }

    T w() const
    {
        return m_size.x();
    }

    T h() const
    {
        return m_size.y();
    }

    T x1() const
    {
        return x();
    }

    T x2() const
    {
        return x() + w();
    }

    T y1() const
    {
        return y();
    }

    T y2() const
    {
        return y() + h();
    }

    void move( Vec2<T> delta )
    {
        m_position += delta;
        computeCenter();
    }

    void move( T dx, T dy )
    {
        move( Vec2<T>(dx, dy) );
    }
    
    const Vec2<T>& size() const
    {
        return m_size;
    }

private:
    void computeCenter()
    {
        m_center.set(x() + w() / 2, y() + h() / 2);
    }

    Vec2<T> m_position, m_size, m_center;

};

typedef Rect<float> Rectf;
typedef Rect<int> Recti;

template <typename T>
bool intersect(Rect<T> a, Rect<T> b)
{
    return a.x1() < b.x2() && a.x2() > b.x1() &&
           a.y1() < b.y2() && a.y2() > b.y1();
}

template <typename T>
float clamp(T v, T min, T max )
{
    return std::max(std::min(v, max), min);
}

template <typename T>
Rect<T> clamp( Rect<T> container, Rect<T> contained )
{
    Rect<T> rect;
    rect.x( clamp<T>(contained.x(), container.x(), container.x() + container.w() ) );
    rect.y( clamp<T>(contained.y(), container.y(), container.y() + container.w() ) );
    return rect;
}




}
}
