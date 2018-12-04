#include "texturenode.h"



namespace aether {
namespace scene {





void TextureNode::set(const graphics::TextureRegion &tr)
{
    m_texregion = tr;
}

void TextureNode::render()
{
    m_texregion.draw(renderPos().x(), renderPos().y());
}




}
}
