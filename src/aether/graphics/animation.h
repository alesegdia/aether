#pragma once

#include <memory>
#include <cmath>
#include <cassert>
#include "spritesheet.h"


namespace aether {
namespace graphics {


struct AnimationFrame
{
    const TextureRegion* texture;
    uint64_t frame_duration;
    uint64_t accumulated_duration;
};

struct AnimationData
{
    void reset();

    void render(float x, float y);

    uint64_t timer = 0;
    AnimationFrame* currentFrame = nullptr;
    size_t animationFrameIndex = 0;
};

class Animation
{
public:

    typedef std::shared_ptr<Animation> SharedPtr;

    Animation(uint64_t default_frame_duration = 500);

    /**
     * @brief addFrame adds a frame with a specified duration
     * @param texture
     * @param duration
     */
    void addFrame(const TextureRegion* texture, uint64_t duration);

    /**
     * @brief addFrame adds a frame with the default set frame duration
     * @param texture
     */
    void addFrame(const TextureRegion* texture);

    /**
     * @brief addFrames adds a list of frames with the default set frame duration
     * @param frames
     */
    void addFrames(std::vector<const TextureRegion*> frames);

    /**
     * @brief reset resets the AnimationData state for this animation
     * @param data
     */
    void reset( AnimationData& data );

    /**
     * @brief updates frame and fix timer to data
     * @param data the animation data to be updated
     */
    void updateData( AnimationData& data );

    const AnimationFrame& getFrame(size_t i)
    {
        return m_frames[i];
    }


private:
    std::vector<AnimationFrame> m_frames;
    uint64_t m_defaultFrameDuration = 0;
    uint64_t m_totalAnimDuration = 0;

};


}
}
