
#include <cassert>
#include <utility>
#include "spritesheet.h"

namespace aether::render {

Spritesheet::~Spritesheet()
= default;

std::vector<const TextureRegion*> Spritesheet::getAllFrames()
{
    return getFrames(0, m_frames.size() - 1);
}


Spritesheet::Spritesheet(size_t width, size_t height, Texture* texture)
{
    Reset( width, height, std::move(texture) );
}

Spritesheet::Spritesheet() = default;

const TextureRegion *Spritesheet::GetFrame(size_t num_frame) const
{
    assert( num_frame < m_frames.size() );
    return &m_frames[num_frame];
}

const TextureRegion *Spritesheet::GetFrame(size_t x_frame, size_t y_frame) const
{
    size_t index = CoordToIndex(x_frame, y_frame);
    assert( index < m_frames.size() );
    return GetFrame(CoordToIndex(x_frame, y_frame));
}

std::vector<const TextureRegion*> Spritesheet::getFrames(size_t start, size_t end)
{
    assert( start <= m_frames.size() );
    assert( end <= m_frames.size() );

    std::vector<const TextureRegion*> frames;
    for( size_t i = start; i <= end; i++ )
    {
        frames.push_back(&m_frames[i]);
    }

    return frames;
}

void Spritesheet::Reset(size_t width, size_t height, Texture* texture)
{
    m_width = int(width);
    m_height = int(height);

    auto size = texture->GetSize();
    int tw = size.GetX() / m_width;
    int th = size.GetY() / m_height;

    m_frames.clear();

    for( int i = 0; i < m_height; i++ )
    {
        for( int j = 0; j < m_width; j++ )
        {
            m_frames.emplace_back(texture, j * tw, i * th, tw, th);
        }
    }
}

void Spritesheet::Load(size_t width, size_t height, Texture* texture)
{
    Reset(width, height, texture);
}

size_t Spritesheet::CoordToIndex(size_t x, size_t y) const
{
    return y * m_width + x;
}

}

