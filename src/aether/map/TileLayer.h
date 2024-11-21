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

		struct TileInstance
		{
			int tilesetId = -1;
			unsigned id = 0;
			unsigned gid = 0;
		};

		class TileLayer : public Layer {
		public:

			using Data = rztl::Matrix2D<TileInstance>;
			using Shared = std::shared_ptr<TileLayer>;

			TileLayer(const Tmx::TileLayer& layer, std::shared_ptr<TilesetCollection> tilesetCollection);

			void SetTileset(TileSet::Shared tileset);

			glm::fvec2 GetTileUV() const;

			void SetMapSize(size_t mapWidth, size_t mapHeight);

			void SetTileSize(size_t tileWidth, size_t tileHeight);

			void SetData(const Data& data);

			TileSet::Shared GetTileSet();

			TileCollisionBehaviour GetTileCollisionBehaviour(size_t x, size_t y) const;

			int GetTileWidth() const;

			int GetTileHeight() const;

			Tile* GetTile(int x, int y)
			{
				auto cell = m_data->GetCell(x, y);
				return cell.gid == 0 ? nullptr : m_tileset->GetTile(cell.gid);
			}

			TileInstance* GetTileInstance(int x, int y)
			{
				if (y >= m_data->GetRowsNumber() && x >= m_data->GetColsNumber() && x < 0 && y < 0)
				{
					return nullptr;
				}
				return &m_data->GetCell(x, y);
			}

			int GetMapWidth() const
			{
				return int(m_mapSizeInTiles.GetX());
			}

			int GetMapHeight() const
			{
				return int(m_mapSizeInTiles.GetY());
			}

			bool IsValidTile(size_t x, size_t y) const;

			void AddProperty(const std::string& key, const std::string& value);

			/*
			bool IsUnsetTile(size_t x, size_t y) const
			{
				return m_data->GetCell(x, y)->tile == nullptr;
			}
			*/

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