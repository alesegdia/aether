#include "aether/map/TileLayer.h"

namespace aether::tilemap
{

	TileSet::Shared TileLayer::GetTileSet()
	{
		return m_tileset;
	}

	TileLayer::TileLayer(const Tmx::TileLayer& tmxTileLayer, std::shared_ptr<TilesetCollection> tilesetCollection)
		: Layer(tmxTileLayer.GetName(), tmxTileLayer.GetZOrder())
	{
		bool hasVisibleProp = tmxTileLayer.GetProperties().HasProperty("visible");
		bool visiblePropOn = tmxTileLayer.GetProperties().GetBoolProperty("visible");
		SetVisible(!hasVisibleProp || visiblePropOn);
		SetMapSize(tmxTileLayer.GetWidth(), tmxTileLayer.GetHeight());
		
		TileLayer::Data rawData(size_t(tmxTileLayer.GetWidth()), size_t(tmxTileLayer.GetHeight()));

		// Set tile data for the layer
		for (int i = 0; i < tmxTileLayer.GetWidth(); i++)
		{
			for (int j = 0; j < tmxTileLayer.GetHeight(); j++)
			{
				auto tmxTileInstance = tmxTileLayer.GetTile(i, j);
				
				TileInstance tileInstance;
				tileInstance.gid = tmxTileInstance.gid;
				tileInstance.id = tmxTileInstance.id;
				tileInstance.tilesetId = tmxTileInstance.tilesetId;
				
				// auto tileset = tilesetCollection->GetTilesets()[size_t(tileInstance.tilesetId)];
				// tileInstance.tile = tileset->GetTile(tileInstance.id);

				rawData.SetCell(size_t(i), size_t(j), tileInstance);
			}
		}
		SetData(rawData);
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
			if (cell.id == -1) {
				return TileCollisionBehaviour::Empty;
			}
			return m_tileset->GetTile(cell.id)->GetCollisionBehaviour();
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


	glm::fvec2 TileLayer::GetTileUV() const
	{
		return glm::fvec2(1.0f / m_tileset->GetColumns(), 1.0f / m_tileset->GetRows());
	}


}