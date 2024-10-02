#pragma once

#include <memory>
#include <cmath>
#include <cassert>
#include <functional>
#include <list>
#include "aether/render/Animation.h"

namespace aether::render {

    /**
     * @brief Manages and triggers animations.
     */
    class AnimationsManager
    {
    private:
        /**
         * @brief Represents an entry of an animation in the manager.
         */
        struct Entry
        {
            std::shared_ptr<Animation> animation; ///< The animation object.
            AnimationData animData; ///< Data related to the animation.
            aether::math::Vec2i position; ///< Position of the animation.

            /**
             * @brief Constructs an Entry object.
             * @param anim The animation object.
             * @param x The x-coordinate of the animation position.
             * @param y The y-coordinate of the animation position.
             * @param onEnd Callback function to be called when the animation ends.
             */
            Entry(std::shared_ptr<Animation> anim, int x, int y, std::function<void(void)> onEnd);
        };

    public:
        static AnimationsManager instance; ///< Singleton instance of the AnimationsManager.

        /**
         * @brief Adds an animation to the manager with a callback function.
         * @param animation The animation object.
         * @param x The x-coordinate of the animation position.
         * @param y The y-coordinate of the animation position.
         * @param onAnimationFinished Callback function to be called when the animation ends.
         */
        void AddAnimation(std::shared_ptr<Animation> animation, int x, int y, std::function<void(void)> onAnimationFinished);

        /**
         * @brief Adds an animation to the manager without a callback function.
         * @param animation The animation object.
         * @param x The x-coordinate of the animation position.
         * @param y The y-coordinate of the animation position.
         */
        void AddAnimation(std::shared_ptr<Animation> animation, int x, int y);

        /**
         * @brief Updates all animations in the manager.
         * @param delta The time delta in milliseconds.
         */
        void Update(uint64_t delta);

        /**
         * @brief Renders all animations in the manager.
         */
        void Render();

    private:
        std::list<Entry> m_entries; ///< List of animation entries.
    };

}