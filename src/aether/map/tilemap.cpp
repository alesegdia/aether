#include "aether/map/tilemap.h"

#include <utility>

#include "aether/render/IRenderModule.h"


namespace aether {
namespace tilemap {


std::shared_ptr<TileMap> BuildMap(const Tmx::Map &inmap, aether::render::IRenderModule* renderer)
{
    std::shared_ptr<TileMap> outmap(new TileMap());
    outmap->SetBasePath(inmap.GetFilepath());

    std::vector<TileSet::Shared> tilesets;

    // parse tilesets
    for( auto tileset : inmap.GetTilesets() ) {

        auto newTileset = std::make_shared<TileSet>();
        tilesets.push_back(newTileset);
        outmap->AddTileset(newTileset);
        newTileset->SetName(tileset->GetName());
        newTileset->SetTileSize(tileset->GetTileWidth(), tileset->GetTileHeight());

        auto path = inmap.GetFilepath() + "/" + tileset->GetImage()->GetSource();
        render::Texture* t = renderer->LoadTextureFromFile(path);

        auto columns = tileset->GetImage()->GetWidth() / tileset->GetTileWidth();
        auto rows = tileset->GetImage()->GetHeight() / tileset->GetTileHeight();
        auto newSheet = std::make_shared<render::Spritesheet>(columns, rows, t);
        outmap->AddSheet(newSheet);
        newTileset->SetFirstGid(tileset->GetFirstGid());

        for( int i = 0; i < rows; i++ ) {
            for( int j = 0; j < columns; j++ ) {
                auto index = i * columns + j;
                auto frame = newSheet->GetFrame(index);
                newTileset->AddTile(index, frame, TileCollisionBehaviour::Empty);
            }
        }

        for( auto tile : tileset->GetTiles() ) {

            // set collision behaviour
            auto tileId = tile->GetId();
            auto newTile = newTileset->GetTile(tileId);
            if( tile->GetProperties().HasProperty("collision") ) {
                auto collisionType = tile->GetProperties().GetStringProperty("collision");
                if( collisionType == "solid" )
                {
                    newTile->collisionBehaviour = TileCollisionBehaviour::Solid;
                }
                else if( collisionType == "oneway" )
                {
                    newTile->collisionBehaviour = TileCollisionBehaviour::Oneway;
                }
                else if (collisionType == "empty")
                {
                    newTile->collisionBehaviour = TileCollisionBehaviour::Empty;
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

        bool hasVisibleProp = tmxTileLayer->GetProperties().HasProperty("visible");
        bool visiblePropOn = tmxTileLayer->GetProperties().GetBoolProperty("visible");

        std::shared_ptr<TileLayer> tileLayer = std::make_shared<TileLayer>(layer->GetName(), layer->GetZOrder());
        tileLayer->SetMapSize(tmxTileLayer->GetWidth(), tmxTileLayer->GetHeight());
        outmap->AddTileLayer(tileLayer);
        TileLayer::Data rawData(size_t(tmxTileLayer->GetWidth()), size_t(tmxTileLayer->GetHeight()));
        auto tileset = outmap->GetTileset(tilesetId);
        tileLayer->SetTileSize(tileset->GetTileSize().GetX(), tileset->GetTileSize().GetY());

        for( int i = 0; i < tmxTileLayer->GetWidth(); i++ ) {
            for( int j = 0; j < tmxTileLayer->GetHeight(); j++ ) {
                auto cellValue = -1;
                auto tilesetId = tmxTileLayer->GetTile(i, j).tilesetId;
                if( tilesetId != -1 ) {
                    tileLayer->SetTileset(tilesets[size_t(tilesetId)]);
                    auto firstGid = tilesets[size_t(tilesetId)]->GetFirstGid();
                    cellValue = int(tmxTileLayer->GetTileId(i, j));
                }
                rawData.SetCell(size_t(i), size_t(j), cellValue);
            }
        }
        tileLayer->SetVisible(!hasVisibleProp || visiblePropOn);
        tileLayer->SetData(rawData);
    }

    for( auto group : inmap.GetObjectGroups() ) {
        auto newObjectLayer = std::make_shared<ObjectLayer>(group->GetName(), group->GetZOrder());
        outmap->AddObjectLayer(newObjectLayer);
        for( auto object : group->GetObjects() ) {
            auto& newObject = newObjectLayer->CreateNewObject(object->GetName(),
                                                        object->GetX(), object->GetY(),
                                                        object->GetWidth(), object->GetHeight());
            for( auto prop : object->GetProperties().GetList() ) {
                newObject.props[prop.first] = prop.second;
            }
        }
    }

    return outmap;
}

Tile::Tile(const render::TextureRegion *tex, TileCollisionBehaviour tcb)
    : texture(tex),
      collisionBehaviour(tcb)
{

}

Tile *TileSet::GetTile(uint16_t tile_index)
{
    if(tile_index >= m_tiles.size())
    {
        return nullptr;
    }
    Tile& tile = m_tiles[tile_index];
    return &tile;
}

Tile &TileSet::AddTile(size_t index, const render::TextureRegion *tex, TileCollisionBehaviour tcb)
{
    assert(index >= 0);
    while( m_tiles.size() <= index ) {
        m_tiles.emplace_back(nullptr, TileCollisionBehaviour::Empty);
    }
    m_tiles[index] = Tile(tex, tcb);
    return m_tiles[index];
}

void TileSet::SetName(const std::string &name)
{
    m_name = name;
}

void TileSet::SetFirstGid(int gid)
{
    m_gid = gid;
}

int TileSet::GetFirstGid()
{
    return m_gid;
}

const math::Vec2i &TileSet::GetTileSize()
{
    return m_tileSize;
}

void TileSet::SetTileSize(int w, int h)
{
    m_tileSize.Set(w, h);
}

Layer::Layer(const std::string &id, int zOrder)
{
    m_name = id;
    m_depthOrder = zOrder;
}

Layer::~Layer() = default;

const std::string &Layer::GetName()
{
    return m_name;
}

int Layer::GetDepthOrder() const
{
    return m_depthOrder;
}

ObjectLayer::ObjectLayer(const std::string &id, int zOrder)
    : Layer(id, zOrder)
{

}

ObjectLayer::Object &ObjectLayer::CreateNewObject(const std::string &name, int x, int y, int w, int h)
{
    Object object;
    object.name = name;
    object.aabb = {x, y, w, h};
    m_objects.push_back(object);
    return m_objects.back();
}

const std::vector<ObjectLayer::Object> &ObjectLayer::GetAllObjects() const
{
    return m_objects;
}

void ObjectLayer::Render()
{

}

TileLayer::TileLayer(const std::string &id, int zOrder)
    : Layer(id, zOrder)
{

}

void TileLayer::SetTileset(TileSet::Shared tileset)
{
    m_tileset = std::move(tileset);
}

void TileLayer::SetMapSize(size_t mapWidth, size_t mapHeight)
{
    m_mapSizeInTiles.Set(mapWidth, mapHeight);
}

void TileLayer::SetTileSize(size_t tileWidth, size_t tileHeight)
{
    m_tileSize.Set(float(tileWidth), float(tileHeight));
}

void TileLayer::SetData(const TileLayer::Data& data)
{
    assert(data.GetColsNumber() == m_mapSizeInTiles.GetX() && data.GetRowsNumber() == m_mapSizeInTiles.GetY());
    m_data.reset(new Data(data));
}

TileSet::Shared TileLayer::GetTileSet()
{
    return m_tileset;
}

TileCollisionBehaviour TileLayer::GetTileCollisionBehaviour(size_t x, size_t y) const
{
    if(x >= 0 && x < m_data->GetColsNumber() &&
       y >= 0 && y < m_data->GetRowsNumber())
    {
        auto cell = m_data->GetCell(x, y);
        if (cell == -1 || m_tileset->GetTile(cell) == nullptr) {
            return TileCollisionBehaviour::Empty;
        }
        return m_tileset->GetTile(cell)->collisionBehaviour;
    }
    return TileCollisionBehaviour::Empty;
}

aether::math::Vec2i TileMap::GetObjectTilePosition(const ObjectLayer::Object& object)
{
    auto vec = object.aabb.position() / 16;
    return vec;
}

int TileLayer::GetTileWidth() const
{
    return int(m_tileSize.GetX());
}

int TileLayer::GetTileHeight() const
{
    return int(m_tileSize.GetY());
}

bool TileLayer::IsValidTile(size_t x, size_t y) const
{
    return x < m_mapSizeInTiles.GetX() &&
           y < m_mapSizeInTiles.GetY();
}

void TileLayer::Render()
{
    /*
    for( size_t i = 0; i < m_data->GetRowsNumber(); i++ )
    {
        for( size_t j = 0; j < m_data->GetColsNumber(); j++ )
        {
            int cell = m_data->GetCell(j, i);
            if( cell != -1 ) {
                Tile* t = m_tileset->GetTile(cell);
                if( t != nullptr && t->texture != nullptr) {
                    t->texture->Draw(j * m_tileSize.GetX(), i * m_tileSize.GetY());
                }
            }
        }
    }
    */
}

void TileLayer::AddProperty(const std::string &key, const std::string &value)
{
    m_props[key] = value;
}

void TileMap::AddSheet(const render::Spritesheet::SharedPtr& sheet)
{
    m_sheetStore.push_back(sheet);
}

void TileMap::AddTileset(const TileSet::Shared& tileset)
{
    m_tilesets.push_back(tileset);
}

void TileMap::AddTileLayer(const TileLayer::Shared& tilelayer)
{
    AddLayer(tilelayer);
    m_tileLayers[tilelayer->GetName()] = tilelayer;
}

void TileMap::AddObjectLayer(const ObjectLayer::Shared& objectLayer)
{
    AddLayer(objectLayer);
    m_objectLayers[objectLayer->GetName()] = objectLayer;

}

TileLayer::Shared TileMap::GetTileLayer(const std::string &layerId)
{
    assert(m_tileLayers.count(layerId) > 0);
    return m_tileLayers[layerId];
}

ObjectLayer::Shared TileMap::GetObjectLayer(const std::string &layerId)
{
    assert(m_objectLayers.count(layerId) > 0);
    return m_objectLayers[layerId];
}

TileSet::Shared TileMap::GetTileset(int i)
{
    assert(i < m_tilesets.size() && i >= 0);
    return m_tilesets[i];
}

void TileMap::Render()
{
    /*
    aether::graphics::hold_bitmap(true);
    for( auto layer : m_layers )
    {
        if (layer->IsVisible())
        {
            layer->Render();
        }
    }
    aether::graphics::hold_bitmap(false);
    */
}

std::unordered_map<std::string, TileLayer::Shared> &TileMap::GetTileLayers()
{
    return m_tileLayers;
}

void TileMap::SetBasePath(const std::string &basePath)
{
    m_basePath = basePath;
}

const std::string &TileMap::GetBasePath()
{
    return m_basePath;
}


}
}
