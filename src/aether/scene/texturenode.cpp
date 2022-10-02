#include "texturenode.h"



namespace aether {
namespace scene {



void TextureNode::SetTextureRegion(const graphics::TextureRegion &tr)
{
    m_texregion = tr;
}

void TextureNode::Render()
{
    float rx, ry, rw, rh;
    rx = m_texregion.GetClip().x();
    ry = m_texregion.GetClip().y();
    rw = m_texregion.GetClip().w();
    rh = m_texregion.GetClip().h();
    m_texregion.GetTexture().Draw(m_renderPosition.GetX(), m_renderPosition.GetY(),
                               rx, ry, rw, rh,      // sub region coordinates
                               m_color,             // tint
                               false, false,        // xflip and yflip
                               rw/2.f, rh/2.f,      // rotation center (middle)
                               m_angle              // rotation angle
                               );
}



}
}
