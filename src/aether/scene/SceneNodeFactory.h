#pragma once

#include <glm/glm.hpp>

namespace aether::scene {

    class ISpriteNode;
    class ITilemapNode;

    class ISceneNodeFactory
    {
    public:
        virtual ISpriteNode* CreateSpriteNode(const glm::fvec2& size) = 0;
        virtual ITilemapNode* CreateTilemapNode() = 0;
    };
}
