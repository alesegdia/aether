
#include "handle.h"


namespace aether {
namespace core {


Handle::Handle()
{
    m_handle = -1;
}

Handle::Handle(const Handle &other)
{
    m_handle = other.m_handle;
}

bool Handle::valid()
{
    return m_handle != -1;
}

int Handle::handle() const
{
    return m_handle;
}

void Handle::handle(int h)
{
    m_handle = h;
}

void Handle::invalidate()
{
    m_handle = -1;
}


}
}
