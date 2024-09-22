#pragma once

#include "aether/math/matrix.h"
#include "aether/math/vec.h"
#include "aether/render/spritesheet.h"

#include "aether/core/utility.h"

#include <vector>
#include <functional>

#include <Tmx.h>


class IRenderModule;

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
    Tile(const render::TextureRegion* tex, TileCollisionBehaviour tcb);

    const render::TextureRegion* texture;
    TileCollisionBehaviour collisionBehaviour = TileCollisionBehaviour::Empty;
    std::unordered_map<std::string, std::string> props;
};


class TileSet
{
public:
    using Shared = std::shared_ptr<TileSet>;

    Tile* GetTile( uint16_t tile_index );

    Tile& AddTile(size_t index, const render::TextureRegion* tex, TileCollisionBehaviour tcb);

    void SetName(const std::string& name);

    void SetFirstGid( int gid );

    int GetFirstGid();

    const math::Vec2i& GetTileSize();

    void SetTileSize(int w, int h);

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
    virtual void Render() = 0;

    const std::string& GetName();

    int GetDepthOrder() const;

    void SetVisible(bool visible)
    {
        m_visible = visible;
    }

    bool IsVisible()
    {
        return m_visible;
    }

private:
    std::string m_name;
    int m_depthOrder = 0;
    bool m_visible = true;

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

    Object& CreateNewObject(const std::string& name, int x, int y, int w, int h);

    const std::vector<Object>& GetAllObjects() const;

    void ForEachObject(std::function<void(const Object&)> callback)
    {
        for( const auto& object : m_objects )
        {
            callback(object);
        }
    }

    void Render() override;

private:
    std::vector<Object> m_objects;

};


class TilesetCollection
{
public:
    Tile* GetTile(int tileID)
    {
        return m_tilesets[0]->GetTile(tileID);
    }

    void AddTileset(const std::shared_ptr<TileSet>& tileset)
    {
        aether::core::insert_sorted(m_tilesets, tileset, [](const std::shared_ptr<TileSet> a, const std::shared_ptr<TileSet> b)
            {
                return a->GetFirstGid() > b->GetFirstGid();
            });
    }

private:
    std::vector<std::shared_ptr<TileSet>> m_tilesets;
};


class TileLayer : public Layer {
public:

    using Data = math::Matrix2D<int>;
    using Shared = std::shared_ptr<TileLayer>;

    TileLayer(const std::string& id, int zOrder);

    void SetTileset(TileSet::Shared tileset);

    void SetMapSize(size_t mapWidth, size_t mapHeight);

    void SetTileSize(size_t tileWidth, size_t tileHeight);

    void SetData(const Data& data);

    TileSet::Shared GetTileSet();

    TileCollisionBehaviour GetTileCollisionBehaviour( size_t x, size_t y ) const;

    int GetTileWidth() const;

    int GetTileHeight() const;

    int GetMapWidth() const
    {
        return int(m_mapSizeInTiles.GetX());
    }

    int GetMapHeight() const
    {
        return int(m_mapSizeInTiles.GetY());
    }

    bool IsValidTile(size_t x, size_t y) const;

    void Render() override;

    void AddProperty(const std::string& key, const std::string& value);

    bool IsUnsetTile(size_t x, size_t y)
    {
        return m_data->GetCell(x, y) == -1;
    }

private:
    std::unique_ptr<Data> m_data;
    std::shared_ptr<TileSet> m_tileset;
    std::map<std::string, std::string> m_props;
    math::Vec2sz m_mapSizeInTiles;
    math::Vec2f m_tileSize;
    std::shared_ptr<TilesetCollection> m_tilesetCollection;

};



template <typename ResourceType>
class ResourceStore {
public:

    using SharedRes = std::shared_ptr<ResourceType>;

    template <typename... Args>
    const SharedRes& Create(const std::string& id, Args... args)
    {
        m_storage[id] = std::make_shared<ResourceType>(args...);
        return m_storage[id];
    }

    const SharedRes& Get(const std::string& id)
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

    TileMap()
    {
        m_tilesetCollection = std::make_shared<TilesetCollection>();
    }

    void AddSheet(const render::Spritesheet::SharedPtr& sheet);

    void AddTileset(const TileSet::Shared& tileset);

    void AddTileLayer(const TileLayer::Shared& tilelayer);

    void AddObjectLayer(const ObjectLayer::Shared& objectLayer);

    aether::math::Vec2i GetObjectTilePosition(const ObjectLayer::Object& object);

    template<typename LayerType>
    void AddLayer(std::shared_ptr<LayerType> layer)
    {
        static_assert(std::is_base_of<Layer, LayerType>::value);
        m_layers.push_back(std::static_pointer_cast<Layer>(layer));
    }

    TileLayer::Shared GetTileLayer(const std::string& layerId);

    ObjectLayer::Shared GetObjectLayer(const std::string& layerId);

    TileSet::Shared GetTileset(int i);

    void Render();

    std::unordered_map<std::string, TileLayer::Shared>& GetTileLayers();

    void SetBasePath(const std::string& basePath);

    const std::string& GetBasePath();

    float GetWidth() const
    {
        assert(!m_layers.empty() && "must have some tile layer to fetch width");
        const auto& layer = *(*(m_tileLayers.begin())).second;
        return float(layer.GetMapWidth() * layer.GetTileWidth());
    }

    float GetHeight() const
    {
        assert(!m_layers.empty() && "must have some tile layer to fetch height");
        const auto& layer = *(*(m_tileLayers.begin())).second;
        return float(layer.GetMapHeight() * layer.GetTileHeight());
    }

private:
    std::vector<Layer::Shared> m_layers;
    std::vector<TileSet::Shared> m_tilesets;
    std::shared_ptr<TilesetCollection> m_tilesetCollection;
    std::vector<aether::render::Spritesheet::SharedPtr> m_sheetStore;
    std::unordered_map<std::string, TileLayer::Shared> m_tileLayers;
    std::unordered_map<std::string, ObjectLayer::Shared> m_objectLayers;
    std::string m_basePath;

};


std::shared_ptr<TileMap> BuildMap(const Tmx::Map& inmap, aether::render::IRenderModule* module);


}
}
