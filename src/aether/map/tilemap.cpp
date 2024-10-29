#include "aether/map/tilemap.h"

#include <utility>

#include "aether/render/IRenderModule.h"

#include "TmxTileLayer.h"

#include "aether/core/Engine.h"

namespace aether {
    namespace tilemap {

        std::shared_ptr<TileMap> BuildMap(const Tmx::Map& inmap)
        {
            // Create a new TileMap object
            std::shared_ptr<TileMap> outmap(new TileMap());
            outmap->SetBasePath(inmap.GetFilepath());

            std::vector<TileSet::Shared> tilesets;

            // Parse tilesets from the input map
            for (auto tileset : inmap.GetTilesets()) {
                auto newTileset = std::make_shared<TileSet>();
                tilesets.push_back(newTileset);
                outmap->AddTileset(newTileset);
                newTileset->SetName(tileset->GetName());
                newTileset->SetTileSize(tileset->GetTileWidth(), tileset->GetTileHeight());

                // Load texture for the tileset
                auto path = inmap.GetFilepath() + "/" + tileset->GetImage()->GetSource();
                render::Texture* t = aether::GEngine->GetRenderModuleAccessor()->LoadTextureFromFile(path);

                // Calculate the number of columns and rows in the tileset
                auto columns = tileset->GetImage()->GetWidth() / tileset->GetTileWidth();
                auto rows = tileset->GetImage()->GetHeight() / tileset->GetTileHeight();

                // Create spritesheet for the tileset
                auto newSheet = std::make_shared<render::Spritesheet>(columns, rows, t);
                outmap->AddSheet(newSheet);
                newTileset->SetSpritesheet(newSheet);
                newTileset->SetFirstGid(tileset->GetFirstGid());

                // Add tiles to the tileset
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) {
                        auto index = i * columns + j;
                        auto frame = newSheet->GetFrame(index);
                        newTileset->AddTile(index, frame, TileCollisionBehaviour::Empty);
                    }
                }

                // Set collision behavior for tiles
                for (auto tile : tileset->GetTiles()) {
                    auto tileId = tile->GetId();
                    auto newTile = newTileset->GetTile(tileId);

                    // Set collision behaviour for this tile
                    if (tile->GetProperties().HasProperty("collision")) {
                        auto collisionType = tile->GetProperties().GetStringProperty("collision");
                        if (collisionType == "solid")
                        {
                            newTile->collisionBehaviour = TileCollisionBehaviour::Solid;
                        }
                        else if (collisionType == "oneway")
                        {
                            newTile->collisionBehaviour = TileCollisionBehaviour::Oneway;
                        }
                        else if (collisionType == "empty")
                        {
                            newTile->collisionBehaviour = TileCollisionBehaviour::Empty;
                        }
                    }

                    // Copy properties from the tile
                    for (auto prop : tile->GetProperties().GetList())
                    {
                        newTile->props[prop.first] = prop.second;
                    }
                }
            }

            // Parse layers from the input map
            for (auto layer : inmap.GetTileLayers()) {
                auto tmxTileLayer = static_cast<Tmx::TileLayer*>(layer);
                auto tilesetId = std::max(0, tmxTileLayer->GetTile(0, 0).tilesetId);

                std::shared_ptr<TileLayer> tileLayer = std::make_shared<TileLayer>(layer->GetName(), layer->GetZOrder());

                bool hasVisibleProp = tmxTileLayer->GetProperties().HasProperty("visible");
                bool visiblePropOn = tmxTileLayer->GetProperties().GetBoolProperty("visible");
                tileLayer->SetVisible(!hasVisibleProp || visiblePropOn);

                tileLayer->SetMapSize(tmxTileLayer->GetWidth(), tmxTileLayer->GetHeight());
                outmap->AddTileLayer(tileLayer);
                TileLayer::Data rawData(size_t(tmxTileLayer->GetWidth()), size_t(tmxTileLayer->GetHeight()));
                auto tileset = outmap->GetTileset(tilesetId);
                tileLayer->SetTileSize(tileset->GetTileSize().GetX(), tileset->GetTileSize().GetY());

                // Set tile data for the layer
                for (int i = 0; i < tmxTileLayer->GetWidth(); i++) {
                    for (int j = 0; j < tmxTileLayer->GetHeight(); j++) {
                        auto cellValue = -1;
                        auto tilesetId = tmxTileLayer->GetTile(i, j).tilesetId;
                        if (tilesetId != -1) {
                            tileLayer->SetTileset(tilesets[size_t(tilesetId)]);
                            auto firstGid = tilesets[size_t(tilesetId)]->GetFirstGid();
                            cellValue = int(tmxTileLayer->GetTileId(i, j));
                        }
                        rawData.SetCell(size_t(i), size_t(j), cellValue);
                    }
                }
                tileLayer->SetData(rawData);
            }

            // Parse object groups from the input map
            for (auto group : inmap.GetObjectGroups()) {
                auto newObjectLayer = std::make_shared<ObjectLayer>(group->GetName(), group->GetZOrder());
                outmap->AddObjectLayer(newObjectLayer);
                for (auto object : group->GetObjects()) {
                    auto& newObject = newObjectLayer->CreateNewObject(object->GetName(),
                        object->GetX(), object->GetY(),
                        object->GetWidth(), object->GetHeight());
                    for (auto prop : object->GetProperties().GetList()) {
                        newObject.props[prop.first] = prop.second;
                    }
                }
            }

            return outmap;
        }




        aether::math::Vec2i TileMap::GetObjectTilePosition(const ObjectLayer::Object& object)
        {
            auto vec = object.aabb.position() / 16;
            return vec;
        }

        void TileMap::AddSheet(const std::shared_ptr<render::Spritesheet>& sheet)
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

        TileLayer::Shared TileMap::GetTileLayer(const std::string& layerId)
        {
            assert(m_tileLayers.count(layerId) > 0);
            return m_tileLayers[layerId];
        }

        ObjectLayer::Shared TileMap::GetObjectLayer(const std::string& layerId)
        {
            assert(m_objectLayers.count(layerId) > 0);
            return m_objectLayers[layerId];
        }

        std::unordered_map<std::string, TileLayer::Shared>& TileMap::GetTileLayers()
        {
            return m_tileLayers;
        }

        void TileMap::SetBasePath(const std::string& basePath)
        {
            m_basePath = basePath;
        }

        const std::string& TileMap::GetBasePath()
        {
            return m_basePath;
        }

		TileSet::Shared TileMap::GetTileset(int i)
		{
			assert(i < m_tilesets.size() && i >= 0);
			return m_tilesets[i];
		}

    }
}
