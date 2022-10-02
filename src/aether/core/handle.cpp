
#include "handle.h"


namespace aether {
namespace core {


Handle::Handle()
{
    m_handle = -1;
}

Handle::Handle(int handle)
{
    m_handle = handle;
}

Handle::Handle(const Handle &other)
{
    m_handle = other.m_handle;
}

bool Handle::IsValid() const
{
    return m_handle != -1;
}

bool Handle::IsNotValid() const
{
	return !IsValid();
}

int Handle::GetHandle() const
{
    return m_handle;
}

void Handle::SetHandle(int h)
{
    m_handle = h;
}

void Handle::Invalidate()
{
    m_handle = -1;
}


}
}
