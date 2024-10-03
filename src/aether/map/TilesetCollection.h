#pragma once

#include "aether/core/utility.h"

namespace aether::tilemap
{

class TilesetCollection
{
public:
	Tile* GetTile(int tileID)
	{
		return m_tilesets[0]->GetTile(tileID);
	}

	void AddTileset(const std::shared_ptr<TileSet>& tileset)
	{
		aether::core::insert_sorted(m_tilesets, tileset, [](const std::shared_ptr<TileSet> a, const std::shared_ptr<TileSet> b)
			{
				return a->GetFirstGid() > b->GetFirstGid();
			});
	}

private:
	std::vector<std::shared_ptr<TileSet>> m_tilesets;
};


}
