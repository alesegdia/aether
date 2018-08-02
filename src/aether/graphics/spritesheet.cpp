
#include <cassert>
#include "spritesheet.h"

namespace aether {
namespace graphics {

Spritesheet::~Spritesheet()
{

}

std::vector<Texture> Spritesheet::getAllFrames()
{
    return getFrames(0, m_frames.size() - 1);
}


Spritesheet::Spritesheet(size_t width, size_t height, Texture texture)
{
    reset( width, height, texture );
}

Texture Spritesheet::getFrame(size_t num_frame)
{
    assert( num_frame < m_frames.size() );
    return m_frames[num_frame];
}

Texture Spritesheet::getFrame(size_t x_frame, size_t y_frame)
{
    size_t index = coordToIndex(x_frame, y_frame);
    assert( index < m_frames.size() );
    return getFrame(coordToIndex(x_frame, y_frame));
}

std::vector<Texture> Spritesheet::getFrames(size_t start, size_t end)
{
    assert( start <= m_frames.size() );
    assert( end <= m_frames.size() );

    std::vector<Texture> frames;
    for( size_t i = start; i <= end; i++ )
    {
        frames.push_back(m_frames[i]);
    }

    return frames;
}

void Spritesheet::reset(size_t width, size_t height, Texture texture)
{
    m_width = int(width);
    m_height = int(height);

    int num_frames = m_width * m_height;
    int tw = texture.width() / m_width;
    int th = texture.height() / m_height;

    m_frames.clear();
    m_frames.reserve(size_t(num_frames));

    for( int i = 0; i < m_height; i++ )
    {
        for( int j = 0; j < m_width; j++ )
        {
            Texture frame = texture.subdivide( j * tw, i * th, tw, th );
            m_frames.push_back(frame);
        }
    }
}

size_t Spritesheet::coordToIndex(size_t x, size_t y)
{
    return y * m_width + x;
}

}
}
