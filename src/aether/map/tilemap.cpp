#include "tilemap.h"

std::shared_ptr<aether::tilemap::TileMap> aether::tilemap::buildMap(const Tmx::Map &inmap)
{
    std::shared_ptr<TileMap> outmap(new TileMap());

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

        for( auto tile : tileset->GetTiles() ) {
#warning TODO: set correct tile collision behaviour, or set it later
            auto tileId = tile->GetId();
            auto visual = newSheet->getFrame(size_t(tileId));
            auto& newTile = newTileset->addTile(tileId, visual, TileCollisionBehaviour::Empty);

            // copy props
            for( auto prop : tile->GetProperties().GetList())
            {
                newTile.props[prop.first] = prop.second;
            }
        }
    }

    // parse layers
    for( auto layer : inmap.GetTileLayers() ) {
        auto tmxTileLayer = static_cast<Tmx::TileLayer*>(layer);
        std::shared_ptr<TileLayer> tileLayer = std::make_shared<TileLayer>();
        tileLayer->setName(tmxTileLayer->GetName());
        tileLayer->setMapSize(tmxTileLayer->GetWidth(), tmxTileLayer->GetHeight());
        outmap->addTileLayer(tileLayer);
        TileLayer::Data rawData(size_t(tmxTileLayer->GetWidth()), size_t(tmxTileLayer->GetHeight()));
        auto tilesetId = tmxTileLayer->GetTile(0, 0).tilesetId;
        auto tileset = outmap->getTileset(tilesetId);
        tileLayer->setTileSize(tileset->tileSize().x(), tileset->tileSize().y());

        for( int i = 0; i < tmxTileLayer->GetWidth(); i++ ) {
            for( int j = 0; j < tmxTileLayer->GetHeight(); j++ ) {
                auto tilesetId = tmxTileLayer->GetTile(i, j).tilesetId;
                tileLayer->setTileset(tilesets[size_t(tilesetId)]);
                auto firstGid = tilesets[size_t(tilesetId)]->getFirstGid();
                auto cell = int(tmxTileLayer->GetTileId(i, j)) - firstGid;
                rawData.set(size_t(i), size_t(j), cell);
            }
        }
        tileLayer->setData(rawData);
    }
    return outmap;
}
