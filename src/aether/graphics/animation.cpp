#include "animation.h"

namespace aether {
namespace graphics {

void AnimationData::reset()
{
    timer = 0;
}

void AnimationData::render(float x, float y)
{
    currentFrame->texture.draw(x, y);
}

Animation::Animation(uint64_t default_frame_duration)
    : m_defaultFrameDuration(default_frame_duration)
{

}

Animation::Animation(const std::vector<TextureRegion>& frames, uint64_t default_frame_duration)
    : Animation(default_frame_duration)
{
    addFrames(frames);
}

void Animation::addFrame(const TextureRegion& texture, int64_t duration)
{
    int64_t accumulated = 0;
    if( m_frames.size() > 0 )
    {
        auto& last_frame = m_frames.back();
        accumulated = last_frame.accumulated_duration + last_frame.frame_duration;
    }
    m_frames.push_back({ texture, duration, accumulated });
    m_totalAnimDuration += duration;
}

void Animation::addFrame(const TextureRegion& texture)
{
    addFrame( texture, m_defaultFrameDuration );
}

void Animation::addFrames(const std::vector<TextureRegion>& frames)
{
    for( auto texture : frames )
    {
        addFrame(texture);
    }
}

void Animation::reset(AnimationData &data)
{
    //assert(data.currentFrame == nullptr && "The AnimationData instance is not null");
    data.reset();
    data.currentFrame = &m_frames[0];
}

void Animation::updateData(AnimationData &data)
{
    assert(data.currentFrame != nullptr);
    AnimationFrame *frame = data.currentFrame;
    int64_t time_accumulated = frame->accumulated_duration;
    size_t frame_index = size_t(data.animationFrameIndex);

    bool lastFrame = frame_index >= m_frames.size();
    while( frame->accumulated_duration + frame->frame_duration < data.timer &&
         !(m_wrapMode == WrapMode::Once && lastFrame) )
    {
        frame_index++;
        time_accumulated = frame->accumulated_duration + frame->frame_duration;

        bool lastFrame = frame_index >= m_frames.size();
        if( frame_index >= m_frames.size() )
        {
            if (m_wrapMode == WrapMode::Once)
            {
                break;
            }
            frame_index = 0;
            data.timer -= m_totalAnimDuration;
        }
        frame = &m_frames[frame_index];
    }

    data.currentFrame = frame;
    data.animationFrameIndex = frame_index;
}


}
}
