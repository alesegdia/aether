#pragma once

#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

namespace aether {
namespace core {

class ResourceManager;
ResourceManager& resmgr();


class IResourceStorage
{
public:
    virtual ~IResourceStorage();
    virtual void cleanup() = 0;
};


class ResourceTraits
{
public:
    template <typename T>
    static uint64_t getIndex() {
        static const uint64_t index = nextTypeIndex++;
        return index;
    }

    static uint64_t getNumResources() {
        return nextTypeIndex;
    }

private:
    static uint64_t nextTypeIndex;

};


template <typename ResourceType>
class ResourceStorage : public IResourceStorage
{
public:
    template <typename... Args>
    void add(Args&&... args)
    {
        m_resources.emplace_back(std::forward<ResourceType>(args)...);
    }

    template <typename... Args>
    ResourceType load(const char* path, Args&&... args)
    {
        if( m_resourcesByString.count(path) == 0 ) {
            ResourceType resource;
            resource.load(path, args...);
            m_resourcesByString[std::string(path)] = resource;
            m_resources.push_back(resource);
            return resource;
        } else {
            return m_resourcesByString[std::string(path)];
        }
    }

    void cleanup() {
        for( auto& resource : m_resources ) {
            resource.destroy();
        }
    }

private:
    std::vector<ResourceType> m_resources;
    std::unordered_map<std::string, ResourceType> m_resourcesByString;

};


class ResourceManager {
public:


    template <typename ResourceType, typename... Args>
    ResourceType load(const char* path, Args&&... args)
    {
        auto index = ResourceTraits::getIndex<ResourceType>();
        ensureIndexFits(index);
        if(m_resourceStorages[index] == nullptr) {
            m_resourceStorages[index] = new ResourceStorage<ResourceType>();
        }
        auto resourceStorage = static_cast<ResourceStorage<ResourceType>*>(m_resourceStorages[index]);
        return resourceStorage->load(path, std::forward<ResourceType>(args)...);
    }

    void cleanup()
    {
        for( auto storage : m_resourceStorages ) {
            storage->cleanup();
            delete storage;
        }
    }


private:

    void ensureIndexFits(uint64_t index)
    {
        for( size_t i = m_resourceStorages.size(); i <= index; i++ ) {
            m_resourceStorages.push_back(nullptr);
        }
    }

    std::vector<IResourceStorage*> m_resourceStorages;

};



}
}
