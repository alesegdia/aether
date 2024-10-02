#pragma once

#include <memory>
#include <cmath>
#include <cassert>
#include <functional>
#include "spritesheet.h"


namespace aether::render {


struct AnimationFrame
{
    TextureRegion texture;
    int64_t frame_duration;
    int64_t accumulated_duration;
};

struct AnimationData
{
    void ResetAnimationTimer();

    void Render(float x, float y);

    int64_t timer = 0;
    AnimationFrame* currentFrame = nullptr;
    size_t animationFrameIndex = 0;
    bool animationFinished = false;
    std::function<void(void)> onAnimationFinished;
};

class Animation
{
public:

    typedef std::shared_ptr<Animation> SharedPtr;

    enum class WrapMode
    {
        Once,
        Loop
    };

    Animation(uint64_t default_frame_duration = 500);
    Animation(const std::vector<TextureRegion>& frames, uint64_t default_frame_duration = 500);

    /**
     * @brief addFrame adds a frame with a specified duration
     * @param texture
     * @param duration
     */
    void AddFrame(const TextureRegion& texture, int64_t duration);

    /**
     * @brief addFrame adds a frame with the default set frame duration
     * @param texture
     */
    void AddFrame(const TextureRegion& texture);

    /**
     * @brief addFrames adds a list of frames with the default set frame duration
     * @param frames
     */
    void AddFrames(const std::vector<TextureRegion>&);

    /**
     * @brief reset resets the AnimationData state for this animation
     * @param data
     */
    void Reset( AnimationData& data );

    /**
     * @brief updates frame and fix timer to data
     * @param data the animation data to be updated
     */
    void UpdateData( AnimationData& data, uint64_t delta );

    const AnimationFrame& GetFrame(size_t i);

    void SetWrapMode(WrapMode wrapMode);


private:
    std::vector<AnimationFrame> m_frames;
    int64_t m_defaultFrameDuration = 0;
    int64_t m_totalAnimDuration = 0;
    WrapMode m_wrapMode = WrapMode::Loop;

};


}
