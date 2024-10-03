#include "aether/map/TileLayer.h"

namespace aether::tilemap
{

	TileSet::Shared TileLayer::GetTileSet()
	{
		return m_tileset;
	}

	TileLayer::TileLayer(const std::string& id, int zOrder)
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


	TileCollisionBehaviour TileLayer::GetTileCollisionBehaviour(size_t x, size_t y) const
	{
		if (x >= 0 && x < m_data->GetColsNumber() &&
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

	void TileLayer::AddProperty(const std::string& key, const std::string& value)
	{
		m_props[key] = value;
	}


}