#pragma once

#include "../math/matrix.h"
#include "../math/vec.h"
#include "../graphics/spritesheet.h"

#include <vector>
#include <functional>

#include <TmxMap.h>
#include <TmxLayer.h>
#include <TmxTileLayer.h>
#include <TmxTileset.h>
#include <TmxTile.h>
#include <TmxObject.h>


namespace aether {
namespace tilemap {


enum class TileCollisionBehaviour : uint8_t
{
    Empty = 0,
    Solid,
    Oneway
};

struct Tile
{
    Tile(const graphics::TextureRegion* tex, TileCollisionBehaviour tcb);

    const graphics::TextureRegion* texture;
    TileCollisionBehaviour collisionBehaviour = TileCollisionBehaviour::Empty;
    std::unordered_map<std::string, std::string> props;
};


class TileSet
{
public:
    using Shared = std::shared_ptr<TileSet>;

    Tile* get( uint16_t tile_index );

    Tile& addTile(size_t index, const graphics::TextureRegion* tex, TileCollisionBehaviour tcb);

    void setName(const std::string& name);

    void setFirstGid( int gid );

    int getFirstGid();

    const math::Vec2i& tileSize();

    void setTileSize(int w, int h);

private:
    std::vector<Tile> m_tiles;
    std::string m_name;
    int m_gid;
    aether::math::Vec2i m_tileSize;

};


class Layer {
public:
    using Shared = std::shared_ptr<Layer>;

    Layer(const std::string& id, int zOrder);

    virtual ~Layer();
    virtual void render() = 0;

    const std::string& getName();

    int zOrder() const;

private:
    std::string m_name;
    int m_zOrder = 0;

};

class ObjectLayer : public Layer {
public:

    struct Object {
        std::string name;
        math::Recti aabb;
        std::unordered_map<std::string, std::string> props;
    };

    using Shared = std::shared_ptr<ObjectLayer>;

    ObjectLayer(const std::string& id, int zOrder);

    Object& newObject(const std::string& name, int x, int y, int w, int h);

    const std::vector<Object>& objects() const;

    void foreach(std::function<void(const Object&)> callback)
    {
        for( const auto& object : m_objects )
        {
            callback(object);
        }
    }

    void render() override;

private:
    std::vector<Object> m_objects;

};

class TileLayer : public Layer {
public:

    using Data = math::Matrix2D<int>;
    using Shared = std::shared_ptr<TileLayer>;

    TileLayer(const std::string& id, int zOrder);

    void setTileset(TileSet::Shared tileset);

    void setMapSize(size_t mapWidth, size_t mapHeight);

    void setTileSize(size_t tileWidth, size_t tileHeight);

    void setData(const Data& data);

    TileSet::Shared tileSet();

    TileCollisionBehaviour getTileCollisionBehaviour( size_t x, size_t y ) const;

    int tileWidth() const;

    int tileHeight() const;

    int mapWidth() const
    {
        return m_mapSizeInTiles.x();
    }

    int mapHeight() const
    {
        return m_mapSizeInTiles.y();
    }

    bool isValidTile(size_t x, size_t y) const;

    void render() override;

    void addProperty(const std::string& key, const std::string& value);

private:
    std::unique_ptr<Data> m_data;
    std::shared_ptr<TileSet> m_tileset;
    std::map<std::string, std::string> m_props;
    math::Vec2sz m_mapSizeInTiles;
    math::Vec2f m_tileSize;
};



template <typename ResourceType>
class ResourceStore {
public:

    using SharedRes = std::shared_ptr<ResourceType>;

    template <typename... Args>
    const SharedRes& create(const std::string& id, Args... args)
    {
        m_storage[id] = std::make_shared<ResourceType>(args...);
        return m_storage[id];
    }

    const SharedRes& get(const std::string& id)
    {
        if(m_storage.count(id) == 0) {
            m_storage[id] = nullptr;
        }
        return m_storage[id];
    }

private:
    std::unordered_map<std::string, std::shared_ptr<ResourceType>> m_storage;
};




class TileMap
{
public:

    void addSheet(const graphics::Spritesheet::SharedPtr& sheet);

    void addTileset(const TileSet::Shared& tileset);

    void addTileLayer(const TileLayer::Shared& tilelayer);

    void addObjectLayer(const ObjectLayer::Shared& objectLayer);

    template<typename LayerType>
    void addLayer(std::shared_ptr<LayerType> layer)
    {
        static_assert(std::is_base_of<Layer, LayerType>::value);
        m_layers.push_back(std::static_pointer_cast<Layer>(layer));
    }

    TileLayer::Shared getTileLayer(const std::string& layerId);

    ObjectLayer::Shared getObjectLayer(const std::string& layerId);

    TileSet::Shared getTileset(int i);

    void render();

    std::unordered_map<std::string, TileLayer::Shared>& getTileLayers();

    void setBasePath(const std::string& basePath);

    const std::string& getBasePath();

    float width() const
    {
        assert(!m_layers.empty() && "must have some tile layer to fetch width");
        const auto& layer = *(*(m_tileLayers.begin())).second;
        return layer.mapWidth() * layer.tileWidth();
    }

    float height() const
    {
        assert(!m_layers.empty() && "must have some tile layer to fetch height");
        const auto& layer = *(*(m_tileLayers.begin())).second;
        return layer.mapHeight() * layer.tileHeight();
    }

private:
    std::vector<Layer::Shared> m_layers;
    std::vector<TileSet::Shared> m_tilesets;
    std::vector<aether::graphics::Spritesheet::SharedPtr> m_sheetStore;
    std::unordered_map<std::string, TileLayer::Shared> m_tileLayers;
    std::unordered_map<std::string, ObjectLayer::Shared> m_objectLayers;
    std::string m_basePath;

};


std::shared_ptr<TileMap> buildMap(const Tmx::Map& inmap);


}
}
