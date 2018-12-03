

#include "resourcemanager.h"


namespace aether {
namespace core {

uint64_t ResourceTraits::nextTypeIndex = 0;

IResourceStorage::~IResourceStorage()
{

}

ResourceManager& resmgr()
{
    static ResourceManager mgr;
    return mgr;
}


}
}
