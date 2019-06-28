#include "tilemap.h"

#include <utility>


namespace aether {
namespace tilemap {


std::shared_ptr<TileMap> buildMap(const Tmx::Map &inmap)
{
    std::shared_ptr<TileMap> outmap(new TileMap());
    outmap->setBasePath(inmap.GetFilepath());

    std::vector<TileSet::Shared> tilesets;

    // parse tilesets
    for( auto tileset : inmap.GetTilesets() ) {

        auto newTileset = std::make_shared<TileSet>();
        tilesets.push_back(newTileset);
        outmap->addTileset(newTileset);
        newTileset->setName(tileset->GetName());
        newTileset->setTileSize(tileset->GetTileWidth(), tileset->GetTileHeight());

        auto path = inmap.GetFilepath() + "/" + tileset->GetImage()->GetSource();
        graphics::Texture t;
        t.load(path.c_str());

        auto columns = tileset->GetColumns();
        auto rows = ceil(tileset->GetTileCount() / float(tileset->GetColumns()));
        auto newSheet = std::make_shared<graphics::Spritesheet>(columns, rows, t);
        outmap->addSheet(newSheet);
        newTileset->setFirstGid(tileset->GetFirstGid());

        for( int i = 0; i < rows; i++ ) {
            for( int j = 0; j < columns; j++ ) {
                auto index = i * columns + j;
                auto frame = newSheet->getFrame(index);
                newTileset->addTile(index, frame, TileCollisionBehaviour::Empty);
            }
        }

        for( auto tile : tileset->GetTiles() ) {

            // set collision behaviour
            auto tileId = tile->GetId();
            auto newTile = newTileset->get(tileId);
            if( tile->GetProperties().HasProperty("collision") ) {
                auto collisionType = tile->GetProperties().GetStringProperty("collision");
                if( collisionType == "solid" ) {
                    newTile->collisionBehaviour = TileCollisionBehaviour::Solid;
                } else if( collisionType == "oneway" ) {
                    newTile->collisionBehaviour = TileCollisionBehaviour::Oneway;
                }
            }

            // copy props
            for( auto prop : tile->GetProperties().GetList())
            {
                newTile->props[prop.first] = prop.second;
            }
        }
    }

    // parse layers
    for( auto layer : inmap.GetTileLayers() ) {

        auto tmxTileLayer = static_cast<Tmx::TileLayer*>(layer);
        auto tilesetId = std::max(0, tmxTileLayer->GetTile(0, 0).tilesetId);

        // IGNORE IF THERE I
        // if( tilesetId == -1 ) continue;

        std::shared_ptr<TileLayer> tileLayer = std::make_shared<TileLayer>(layer->GetName(), layer->GetZOrder());
        tileLayer->setMapSize(tmxTileLayer->GetWidth(), tmxTileLayer->GetHeight());
        outmap->addTileLayer(tileLayer);
        TileLayer::Data rawData(size_t(tmxTileLayer->GetWidth()), size_t(tmxTileLayer->GetHeight()));
        auto tileset = outmap->getTileset(tilesetId);
        tileLayer->setTileSize(tileset->tileSize().x(), tileset->tileSize().y());

        for( int i = 0; i < tmxTileLayer->GetWidth(); i++ ) {
            for( int j = 0; j < tmxTileLayer->GetHeight(); j++ ) {
                auto cellValue = -1;
                auto tilesetId = tmxTileLayer->GetTile(i, j).tilesetId;
                if( tilesetId != -1 ) {
                    tileLayer->setTileset(tilesets[size_t(tilesetId)]);
                    auto firstGid = tilesets[size_t(tilesetId)]->getFirstGid();
                    cellValue = int(tmxTileLayer->GetTileId(i, j));
                }
                rawData.set(size_t(i), size_t(j), cellValue);
            }
        }
        tileLayer->setData(rawData);
    }

    for( auto group : inmap.GetObjectGroups() ) {
        auto newObjectLayer = std::make_shared<ObjectLayer>(group->GetName(), group->GetZOrder());
        outmap->addObjectLayer(newObjectLayer);
        for( auto object : group->GetObjects() ) {
            auto& newObject = newObjectLayer->newObject(object->GetName(),
                                                        object->GetX(), object->GetY(),
                                                        object->GetWidth(), object->GetHeight());
            for( auto prop : object->GetProperties().GetList() ) {
                newObject.props[prop.first] = prop.second;
            }
        }
    }

    return outmap;
}

Tile::Tile(const graphics::TextureRegion *tex, TileCollisionBehaviour tcb)
    : texture(tex),
      collisionBehaviour(tcb)
{

}

Tile *TileSet::get(uint16_t tile_index)
{
    if(tile_index >= m_tiles.size())
    {
        return nullptr;
    }
    Tile& tile = m_tiles[tile_index];
    return &tile;
}

Tile &TileSet::addTile(size_t index, const graphics::TextureRegion *tex, TileCollisionBehaviour tcb)
{
    assert(index >= 0);
    while( m_tiles.size() <= index ) {
        m_tiles.emplace_back(nullptr, TileCollisionBehaviour::Empty);
    }
    m_tiles[index] = Tile(tex, tcb);
    return m_tiles[index];
}

void TileSet::setName(const std::string &name)
{
    m_name = name;
}

void TileSet::setFirstGid(int gid)
{
    m_gid = gid;
}

int TileSet::getFirstGid()
{
    return m_gid;
}

const math::Vec2i &TileSet::tileSize()
{
    return m_tileSize;
}

void TileSet::setTileSize(int w, int h)
{
    m_tileSize.set(w, h);
}

Layer::Layer(const std::string &id, int zOrder)
{
    m_name = id;
    m_zOrder = zOrder;
}

Layer::~Layer() = default;

const std::string &Layer::getName()
{
    return m_name;
}

int Layer::zOrder() const
{
    return m_zOrder;
}

ObjectLayer::ObjectLayer(const std::string &id, int zOrder)
    : Layer(id, zOrder)
{

}

ObjectLayer::Object &ObjectLayer::newObject(const std::string &name, int x, int y, int w, int h)
{
    Object object;
    object.name = name;
    object.aabb = {x, y, w, h};
    m_objects.push_back(object);
    return m_objects.back();
}

const std::vector<ObjectLayer::Object> &ObjectLayer::objects() const
{
    return m_objects;
}

void ObjectLayer::render()
{

}

TileLayer::TileLayer(const std::string &id, int zOrder)
    : Layer(id, zOrder)
{

}

void TileLayer::setTileset(TileSet::Shared tileset)
{
    m_tileset = std::move(tileset);
}

void TileLayer::setMapSize(size_t mapWidth, size_t mapHeight)
{
    m_mapSizeInTiles.set(mapWidth, mapHeight);
}

void TileLayer::setTileSize(size_t tileWidth, size_t tileHeight)
{
    m_tileSize.set(tileWidth, tileHeight);
}

void TileLayer::setData(const TileLayer::Data& data)
{
    assert(data.cols() == m_mapSizeInTiles.x() && data.rows() == m_mapSizeInTiles.y());
    m_data.reset(new Data(data));
}

TileSet::Shared TileLayer::tileSet()
{
    return m_tileset;
}

TileCollisionBehaviour TileLayer::getTileCollisionBehaviour(size_t x, size_t y) const
{
    auto cell = m_data->get( x, y );
    if( cell == -1 || m_tileset->get(cell) == nullptr ) {
        return TileCollisionBehaviour::Empty;
    }
    return m_tileset->get(cell)->collisionBehaviour;
}

int TileLayer::tileWidth() const
{
    return m_tileSize.x();
}

int TileLayer::tileHeight() const
{
    return m_tileSize.y();
}

bool TileLayer::isValidTile(size_t x, size_t y) const
{
    return x < m_mapSizeInTiles.x() &&
           y < m_mapSizeInTiles.y();
}

void TileLayer::render()
{
    for( size_t i = 0; i < m_data->rows(); i++ )
    {
        for( size_t j = 0; j < m_data->cols(); j++ )
        {
            int cell = m_data->get(j, i);
            if( cell != -1 ) {
                Tile* t = m_tileset->get(cell);
                if( t != nullptr && t->texture != nullptr) {
                    t->texture->draw(j * m_tileSize.x(), i * m_tileSize.y());
                }
            }
        }
    }
}

void TileLayer::addProperty(const std::string &key, const std::string &value)
{
    m_props[key] = value;
}

void TileMap::addSheet(const graphics::Spritesheet::SharedPtr& sheet)
{
    m_sheetStore.push_back(sheet);
}

void TileMap::addTileset(const TileSet::Shared& tileset)
{
    m_tilesets.push_back(tileset);
}

void TileMap::addTileLayer(const TileLayer::Shared& tilelayer)
{
    addLayer(tilelayer);
    m_tileLayers[tilelayer->getName()] = tilelayer;
}

void TileMap::addObjectLayer(const ObjectLayer::Shared& objectLayer)
{
    addLayer(objectLayer);
    m_objectLayers[objectLayer->getName()] = objectLayer;

}

TileLayer::Shared TileMap::getTileLayer(const std::string &layerId)
{
    assert(m_tileLayers.count(layerId) > 0);
    return m_tileLayers[layerId];
}

ObjectLayer::Shared TileMap::getObjectLayer(const std::string &layerId)
{
    assert(m_objectLayers.count(layerId) > 0);
    return m_objectLayers[layerId];
}

TileSet::Shared TileMap::getTileset(int i)
{
    assert(i < m_tilesets.size() && i >= 0);
    return m_tilesets[i];
}

void TileMap::render()
{
    for( auto layer : m_layers ) {
        layer->render();
    }
}

std::unordered_map<std::string, TileLayer::Shared> &TileMap::getTileLayers()
{
    return m_tileLayers;
}

void TileMap::setBasePath(const std::string &basePath)
{
    m_basePath = basePath;
}

const std::string &TileMap::getBasePath()
{
    return m_basePath;
}


}
}
