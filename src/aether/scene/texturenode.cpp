#include "texturenode.h"



namespace aether {
namespace scene {



void TextureNode::set(const graphics::TextureRegion &tr)
{
    m_texregion = tr;
}

void TextureNode::render()
{
    float rx, ry, rw, rh;
    rx = m_texregion.clip().x();
    ry = m_texregion.clip().y();
    rw = m_texregion.clip().w();
    rh = m_texregion.clip().h();
    m_texregion.texture().draw(m_renderPosition.x(), m_renderPosition.y(),
                               rx, ry, rw, rh,      // sub region coordinates
                               m_color,             // tint
                               false, false,        // xflip and yflip
                               rw/2.f, rh/2.f,      // rotation center (middle)
                               m_angle              // rotation angle
                               );
}



}
}
