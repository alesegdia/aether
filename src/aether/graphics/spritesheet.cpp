
#include <cassert>
#include "spritesheet.h"

namespace aether {
namespace graphics {

Spritesheet::~Spritesheet()
{

}

std::vector<TextureRegion> Spritesheet::getAllFrames()
{
    return getFrames(0, m_frames.size() - 1);
}


Spritesheet::Spritesheet(size_t width, size_t height, Texture texture)
{
    reset( width, height, texture );
}

Spritesheet::Spritesheet()
{

}

const TextureRegion& Spritesheet::getFrame(size_t num_frame) const
{
    assert( num_frame < m_frames.size() );
    return m_frames[num_frame];
}

const TextureRegion& Spritesheet::getFrame(size_t x_frame, size_t y_frame) const
{
    size_t index = coordToIndex(x_frame, y_frame);
    assert( index < m_frames.size() );
    return getFrame(coordToIndex(x_frame, y_frame));
}

std::vector<TextureRegion> Spritesheet::getFrames(size_t start, size_t end)
{
    assert( start <= m_frames.size() );
    assert( end <= m_frames.size() );

    std::vector<TextureRegion> frames;
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

    int tw = texture.width() / m_width;
    int th = texture.height() / m_height;

    m_frames.clear();

    for( int i = 0; i < m_height; i++ )
    {
        for( int j = 0; j < m_width; j++ )
        {
            m_frames.emplace_back(texture, j * tw, i * th, tw, th);
        }
    }
}

void Spritesheet::load(size_t width, size_t height, Texture texture)
{
    reset(width, height, texture);
}

size_t Spritesheet::coordToIndex(size_t x, size_t y) const
{
    return y * m_width + x;
}

}
}
