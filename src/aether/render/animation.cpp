#include "animation.h"

namespace aether::render {

AnimationsManager AnimationsManager::instance;

void AnimationData::ResetAnimationTimer()
{
    timer = 0;
}

void AnimationData::Render(float x, float y)
{
    //currentFrame->texture->Draw(x, y);
}

Animation::Animation(uint64_t default_frame_duration)
    : m_defaultFrameDuration(default_frame_duration)
{

}

Animation::Animation(const std::vector<TextureRegion>& frames, uint64_t default_frame_duration)
    : Animation(default_frame_duration)
{
    AddFrames(frames);
}

void Animation::AddFrame(const TextureRegion& texture, int64_t duration)
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

void Animation::AddFrame(const TextureRegion& texture)
{
    AddFrame( texture, m_defaultFrameDuration );
}

void Animation::AddFrames(const std::vector<TextureRegion>& frames)
{
    for( auto texture : frames )
    {
        AddFrame(texture);
    }
}

void Animation::Reset(AnimationData &data)
{
    //assert(data.currentFrame == nullptr && "The AnimationData instance is not null");
    data.ResetAnimationTimer();
    data.currentFrame = &m_frames[0];
}

void Animation::UpdateData(AnimationData &data, uint64_t delta)
{
    data.timer += delta;
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

        lastFrame = frame_index >= m_frames.size();
        if( frame_index >= m_frames.size() )
        {
            if (data.onAnimationFinished)
            {
                data.onAnimationFinished();
            }
            if (m_wrapMode == WrapMode::Once)
            {
                break;
            }
            frame_index = 0;
            data.timer -= m_totalAnimDuration;
        }
        frame = &m_frames[frame_index];
    }

    if (lastFrame && m_wrapMode == WrapMode::Once)
    {
        data.animationFinished = true;
    }

    data.currentFrame = frame;
    data.animationFrameIndex = frame_index;
}


const aether::render::AnimationFrame& Animation::GetFrame(size_t i)
{
	return m_frames[i];
}

void Animation::SetWrapMode(WrapMode wrapMode)
{
	m_wrapMode = wrapMode;
}

}
