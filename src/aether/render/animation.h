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

// With this class you can trigger animations
class AnimationsManager
{
private:
    struct Entry
    {
        std::shared_ptr<Animation> animation;
        AnimationData animData;
        aether::math::Vec2i position;

        Entry(std::shared_ptr<Animation> anim, int x, int y, std::function<void(void)> onEnd)
        {
            this->animation = anim;
            this->animation->Reset(animData);
            animData.onAnimationFinished = onEnd;
            this->position.Set(x, y);
        }
    };

public:
    static AnimationsManager instance;

    void AddAnimation(std::shared_ptr<Animation> animation, int x, int y, std::function<void(void)> onAnimationFinished)
    {
        animation->SetWrapMode(aether::render::Animation::WrapMode::Once);
        Entry entry(animation, x, y, onAnimationFinished);
        m_entries.push_back(entry);
    }

    void AddAnimation(std::shared_ptr<Animation> animation, int x, int y)
    {
        AddAnimation(animation, x, y, []() {});
    }

    void Update(uint64_t delta)
    {
        delta = delta / 1000;
        auto it = m_entries.begin();
        while (it != m_entries.end())
        {
            auto& entry = *it;
            entry.animation->UpdateData(entry.animData, delta);
            if (entry.animData.animationFinished)
            {
                it = m_entries.erase(it);
            }
            else
            {
                it++;
            }
        }
    }

    void Render()
    {
        for (auto& item : m_entries)
        {
            item.animData.Render(float(item.position.GetX()), float(item.position.GetY()));
        }
    }

private:
    std::list<Entry> m_entries;

};


}
