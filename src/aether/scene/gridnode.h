#pragma once

#include "scene.h"

#include "../graphics/graphics.h"

namespace aether {
namespace scene {


class GridNode : public SceneNode
{
public:

    GridNode(float x, float y, int numXTiles, int numYTiles, float tileWidth, float tileHeight);

    void render() override;


private:
    float m_numXTiles;
    float m_numYTiles;
    float m_tileWidth;
    float m_tileHeight;

};


}
}
