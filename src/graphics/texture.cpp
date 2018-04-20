#include "texture.h"

namespace aether {
namespace graphics {


Texture::Texture(int handle)
{
    m_handle = handle;
}

Texture::Texture(const Texture& other)
{
    m_handle = other.m_handle;
}

bool Texture::valid()
{
    return m_handle != -1;
}


}
}
