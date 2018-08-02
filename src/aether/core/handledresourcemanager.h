#pragma once

#include <stdio.h>
#include <assert.h>


namespace aether {
namespace core {


template <typename ResourceType, size_t NumResources = 64>
/**
 * @brief The HandledResourceManager class keeps track of resources
 * that are used externally via a handle instead of directly
 * acting with the resource, so we can achieve platform independent code.
 */
class HandledResourceManager
{
public:
    /**
     * @brief createNewHandle creates a new handle with a given resource
     * @param element the resource
     * @return the handle of the newly initializated resource
     */
    int createNewHandle(ResourceType element)
    {
        assert(m_usedResources + 1 < NumResources);
        int handle = m_usedResources;
        m_usedResources++;
        m_resources[handle] = element;
        return handle;
    }

    /**
     * @brief fetchPresentHandle fetches a handle that has been already created
     * @param handle the handle related to the resource wanted
     * @return the resource related to the handle given
     */
    ResourceType fetchPresentHandle(int handle)
    {
        assert( handle >= 0 );
        assert( handle < m_usedResources );
        ResourceType res = m_resources[handle];
        return res;
    }

    /**
     * @brief fetchPresentHandleReference same as fetchPresentHandle but returns a ref
     * @param handle the handle
     * @return a ref to the resource related to the handle given
     */
    ResourceType& fetchPresentHandleReference(int handle)
    {
        assert( handle >= 0 );
        assert( handle < m_usedResources );
        return m_resources[handle];
    }


private:

    ResourceType m_resources[NumResources];
    int m_usedResources = 0;

};


}
}
