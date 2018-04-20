#pragma once

#include <stdio.h>
#include <assert.h>


namespace aether {
namespace core {


template <typename ResourceType, size_t NumResources = 64>
class HandledResourceManager
{
public:
    size_t setNextHandle(ResourceType element)
    {
        assert(m_usedResources + 1 < NumResources);
        int handle = m_usedResources;
        m_usedResources++;
        m_resources[handle] = element;
        return handle;
    }

    ResourceType fetch(int handle)
    {
        assert( handle >= 0 );
        assert( handle < m_usedResources );
        ResourceType res = m_resources[handle];
        return res;
    }

    ResourceType& fetchRef(int handle)
    {
        assert( handle >= 0 );
        assert( handle < m_usedResources );
        return m_resources[handle];
    }


private:
    ResourceType m_resources[NumResources];
    size_t m_usedResources = 0;

};


}
}
