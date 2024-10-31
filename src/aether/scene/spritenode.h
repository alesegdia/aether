#pragma once

#include "aether/scene/SceneNode.h"
#include "aether/render/Animation.h"
#include "aether/render/AsepriteAnimLoader.h"
#include <unordered_map>
#include <memory>
#include <string>

namespace aether::render
{
    class Texture;
    class Animation;
}

namespace aether::scene
{
    class ISpriteNode : public SceneNode
    {
    public:
        ISpriteNode(core::ModuleObject* o);

        virtual void SetClippingRect(float x, float y, float w, float h) = 0;
        virtual void SetTexture(render::Texture* texture) = 0;
		virtual void SetTextureRegion(render::TextureRegion* region) = 0;
        void SetAnimation(std::shared_ptr<render::Animation> anim);

        void PlayAnimation(const std::string& animationName);
        void Step() override;
        void LoadAllAnimations(const render::AsepriteAnimationData& data);
        void AddAnimation(const std::string& name, std::shared_ptr<render::Animation> anim);

    private:
        std::shared_ptr<render::Animation> m_currentAnimation = nullptr;
        render::AnimationData m_animationData;
        std::unordered_map<std::string, std::shared_ptr<render::Animation>> m_animations;
    };
}