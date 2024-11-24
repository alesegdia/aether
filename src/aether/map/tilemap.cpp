#include "aether/map/tilemap.h"

#include <utility>

#include "aether/render/IRenderModule.h"

#include "TmxTileLayer.h"

#include "aether/core/Engine.h"
#include "aether/core/logger.h"

namespace aether {
    namespace tilemap {

        TileMap::TileMap(const Tmx::Map& inmap)
        {
            m_tilesetCollection = std::make_shared<TilesetCollection>();

			SetBasePath(inmap.GetFilepath());
            
            // Parse tilesets from the input map
            for (auto tmxTileset : inmap.GetTilesets())
            {
				auto newTileset = std::make_shared<TileSet>(*tmxTileset, inmap.GetFilepath());
				m_tilesetCollection->AddTileset(newTileset);
            }

            if (m_tilesetCollection->GetTilesets().size() <= 0)
            {
                Logger::LogError() << "No tilesets found in the map file";
                assert("false");
            }

            if (m_tilesetCollection->GetTilesets().size() > 1)
            {
                Logger::LogError() << "The tilemap must have 1 maximum tileset. This is a restriction that will be removed in the future.";
				assert("false");
            }

            // Parse tile layers from the input map
            for (auto tmxLayer : inmap.GetTileLayers())
            {
                auto tmxTileLayer = static_cast<Tmx::TileLayer*>(tmxLayer);
                std::shared_ptr<TileLayer> tileLayer = std::make_shared<TileLayer>(*tmxLayer, m_tilesetCollection);
				AddTileLayer(tileLayer);
            }

            // Parse object groups from the input map
            for (auto group : inmap.GetObjectGroups())
            {
                auto newObjectLayer = std::make_shared<ObjectLayer>(group->GetName(), group->GetZOrder());
                AddObjectLayer(newObjectLayer);
                for (auto object : group->GetObjects())
                {
                    auto& newObject = newObjectLayer->CreateNewObject(object->GetName(),
                        object->GetX(), object->GetY(),
                        object->GetWidth(), object->GetHeight());
                    for (auto prop : object->GetProperties().GetList())
                    {
                        newObject.props[prop.first] = prop.second;
                    }
                }
            }

            m_tileSize.x = inmap.GetTileWidth();
            m_tileSize.y = inmap.GetTileHeight();
            m_mapSizeInTiles.x = inmap.GetWidth();
            m_mapSizeInTiles.y = inmap.GetHeight();
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
			return m_tilesetCollection->GetTilesets()[i];
		}

    }
}
