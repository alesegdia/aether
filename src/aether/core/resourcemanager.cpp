

#include "resourcemanager.h"


namespace aether {
namespace core {

uint64_t ResourceTraits::nextTypeIndex = 0;

IResourceStorage::~IResourceStorage()
= default;

ResourceManager& resmgr()
{
    static ResourceManager mgr;
    return mgr;
}


}
}
