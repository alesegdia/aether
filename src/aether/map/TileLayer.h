#pragma once

#include "aether/math/matrix.h"
#include "aether/math/vec.h"
#include "aether/map/Layer.h"
#include "aether/map/Tile.h"
#include "aether/map/TileSet.h"
#include "aether/map/TilesetCollection.h"
#include <unordered_map>
#include <string>

namespace aether {
    namespace tilemap {

		class TileLayer : public Layer {
		public:

			using Data = rztl::Matrix2Di;
			using Shared = std::shared_ptr<TileLayer>;

			TileLayer(const std::string& id, int zOrder);
			~TileLayer() override
			{
				if (tile_map)
				{
					delete[] tile_map;
					tile_map = NULL;
				}
			}

			void SetTileset(TileSet::Shared tileset);

			void SetMapSize(size_t mapWidth, size_t mapHeight);

			void SetTileSize(size_t tileWidth, size_t tileHeight);

			void SetData(const Data& data);

			TileSet::Shared GetTileSet();

			TileCollisionBehaviour GetTileCollisionBehaviour(size_t x, size_t y) const;

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
			std::unique_ptr<Data> m_data = nullptr;
			std::shared_ptr<TileSet> m_tileset;
			std::unordered_map<std::string, std::string> m_props;
			rztl::Vec2sz m_mapSizeInTiles;
			rztl::Vec2f m_tileSize;
			std::shared_ptr<TilesetCollection> m_tilesetCollection;

		};

    }
}