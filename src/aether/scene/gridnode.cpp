#include "gridnode.h"


namespace aether {
namespace scene {


GridNode::GridNode(float x, float y, int numXTiles, int numYTiles, float tileWidth, float tileHeight)
    : m_numXTiles(numXTiles)
    , m_numYTiles(numYTiles)
    , m_tileWidth(tileWidth)
    , m_tileHeight(tileHeight)
{
    m_relativePosition.set(x, y);
}

void GridNode::render()
{
    auto offx = renderPos().x();
    auto offy = renderPos().y();
    for( float x = offx; x <= offx + m_numXTiles * m_tileWidth; x += m_tileHeight ) {
        aether::graphics::draw_line(x, offy, x, offy + m_tileHeight * m_numYTiles, aether::graphics::Color(0.f,0.f,0.f), 2.f);
    }
    for( float y = offy; y <= offy + m_numYTiles * m_tileHeight; y += m_tileHeight ) {
        aether::graphics::draw_line(offx, y, offx + m_tileWidth * m_numXTiles, y, aether::graphics::Color(0.f,0.f,0.f), 2.f);
    }
}


}
}
