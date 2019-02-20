#pragma once

#include "../math/matrix.h"
#include "../math/vec.h"
#include "../graphics/spritesheet.h"

#include <TmxMap.h>
#include <TmxLayer.h>
#include <TmxTileLayer.h>
#include <TmxTileset.h>
#include <TmxTile.h>

namespace aether {
namespace tilemap {


enum class TileCollisionBehaviour : uint8_t
{
    Empty = 0,
    Solid,
};

struct Tile
{
    Tile(const graphics::TextureRegion* tex, TileCollisionBehaviour tcb)
        : texture(tex),
          collisionBehaviour(tcb)
    {

    }

    const graphics::TextureRegion* texture;
    TileCollisionBehaviour collisionBehaviour = TileCollisionBehaviour::Empty;
    std::unordered_map<std::string, std::string> props;
};


class TileSet
{
public:
    using Shared = std::shared_ptr<TileSet>;

    const Tile& get( uint16_t tile_index ) const
    {
        assert(tile_index < m_tiles.size());
        return m_tiles[tile_index];
    }

    Tile& addTile(int index, const graphics::TextureRegion* tex, TileCollisionBehaviour tcb)
    {
        assert(index >= 0);
        m_tiles.insert(m_tiles.begin() + index, Tile(tex, tcb));
        return *(m_tiles.begin() + index);
    }

    void setName(const std::string& name)
    {
        m_name = name;
    }

    void setFirstGid( int gid )
    {
        m_gid = gid;
    }

    int getFirstGid()
    {
        return m_gid;
    }

    const math::Vec2i& tileSize()
    {
        return m_tileSize;
    }

    void setTileSize(int w, int h)
    {
        m_tileSize.set(w, h);
    }

private:
    std::vector<Tile> m_tiles;
    std::string m_name;
    int m_gid;
    aether::math::Vec2i m_tileSize;

};


class Layer {
public:
    using Shared = std::shared_ptr<Layer>;
    virtual ~Layer() {

    }
    virtual void render() = 0;
};

class TileLayer : public Layer {
public:

    using Data = math::Matrix2D<int>;
    using Shared = std::shared_ptr<TileLayer>;

    void setTileset(TileSet::Shared tileset)
    {
        m_tileset = tileset;
    }

    void setName(const std::string& name)
    {
        m_name = name;
    }

    const std::string& getName()
    {
        return m_name;
    }

    void setMapSize(size_t mapWidth, size_t mapHeight)
    {
        m_mapSizeInTiles.set(mapWidth, mapHeight);
    }

    void setTileSize(size_t tileWidth, size_t tileHeight)
    {
        m_tileSize.set(tileWidth, tileHeight);
    }

    void setData(Data data)
    {
        assert(data.cols() == m_mapSizeInTiles.x() && data.rows() == m_mapSizeInTiles.y());
        m_data.reset(new Data(data));
    }

    TileSet::Shared tileSet()
    {
        return m_tileset;
    }

    TileCollisionBehaviour getTileCollisionBehaviour( size_t x, size_t y ) const
    {
        auto cell = m_data->get( x, y );
        return m_tileset->get(cell).collisionBehaviour;
    }

    int tileWidth() const
    {
        return m_tileSize.x();
    }

    int tileHeight() const
    {
        return m_tileSize.y();
    }

    bool isValidTile(size_t x, size_t y) const
    {
        return x < m_mapSizeInTiles.x() &&
               y < m_mapSizeInTiles.y();
    }

    void render()
    {
        for( size_t i = 0; i < m_data->rows(); i++ )
        {
            for( size_t j = 0; j < m_data->cols(); j++ )
            {
                uint16_t cell = m_data->get(j, i);
                const Tile& t = m_tileset->get(cell);
                t.texture->draw(j * m_tileSize.x(), i * m_tileSize.y());
            }
        }
    }

    void addProperty(const std::string& key, const std::string& value)
    {
        m_props[key] = value;
    }


private:
    std::unique_ptr<Data> m_data;
    std::shared_ptr<TileSet> m_tileset;
    std::map<std::string, std::string> m_props;
    math::Vec2sz m_mapSizeInTiles;
    math::Vec2f m_tileSize;
    std::string m_name;
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

    void addSheet(graphics::Spritesheet::SharedPtr sheet)
    {
        m_sheetStore.push_back(sheet);
    }

    void addTileset(TileSet::Shared tileset)
    {
        m_tilesets.push_back(tileset);
    }

    void addTileLayer(TileLayer::Shared tilelayer)
    {
        addLayer(tilelayer);
        m_tileLayers[tilelayer->getName()] = tilelayer;
    }

    template<typename LayerType>
    void addLayer(std::shared_ptr<LayerType> layer)
    {
        static_assert(std::is_base_of<Layer, LayerType>::value);
        m_layers.push_back(std::static_pointer_cast<Layer>(layer));
    }

    TileLayer::Shared getTileLayer(const std::string& layerId)
    {
        assert(m_tileLayers.count(layerId) > 0);
        return m_tileLayers[layerId];
    }

    TileSet::Shared getTileset(int i)
    {
        return m_tilesets[i];
    }

    void render()
    {
        for( auto layer : m_layers ) {
            layer->render();
        }
    }

private:
    std::vector<Layer::Shared> m_layers;
    std::vector<TileSet::Shared> m_tilesets;
    std::vector<aether::graphics::Spritesheet::SharedPtr> m_sheetStore;
    std::unordered_map<std::string, TileLayer::Shared> m_tileLayers;

};


std::shared_ptr<TileMap> buildMap(const Tmx::Map& inmap);


}
}
