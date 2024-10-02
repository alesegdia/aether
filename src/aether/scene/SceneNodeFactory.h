#pragma once


namespace aether::scene {

    class ISpriteNode;
    class ITilemapNode;

    class ISceneNodeFactory
    {
    public:
        virtual ISpriteNode* CreateSpriteNode() = 0;
        virtual ITilemapNode* CreateTilemapNode() = 0;
    };
}
