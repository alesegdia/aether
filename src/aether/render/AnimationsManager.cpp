#include "AnimationsManager.h"

namespace aether::render {

    AnimationsManager AnimationsManager::instance;

    AnimationsManager::Entry::Entry(std::shared_ptr<Animation> anim, int x, int y, std::function<void(void)> onEnd)
    {
        this->animation = anim;
        this->animation->Reset(animData);
        animData.onAnimationFinished = onEnd;
        this->position.Set(x, y);
    }

    void AnimationsManager::AddAnimation(std::shared_ptr<Animation> animation, int x, int y, std::function<void(void)> onAnimationFinished)
    {
        animation->SetWrapMode(aether::render::Animation::WrapMode::Once);
        Entry entry(animation, x, y, onAnimationFinished);
        m_entries.push_back(entry);
    }

    void AnimationsManager::AddAnimation(std::shared_ptr<Animation> animation, int x, int y)
    {
        AddAnimation(animation, x, y, []() {});
    }

    void AnimationsManager::Update(uint64_t delta)
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

    void AnimationsManager::Render()
    {
        for (auto& item : m_entries)
        {
            item.animData.Render(float(item.position.GetX()), float(item.position.GetY()));
        }
    }

}