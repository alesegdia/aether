#include "aether/map/TilesetCollection.h"
#include "aether/map/TileSet.h"

namespace aether::tilemap
{
	Tile* TilesetCollection::GetTile(int tileID)
	{
		for (auto& tileset : m_tilesets)
		{
			if (tileID >= tileset->GetFirstGid() && tileID <= tileset->GetLastGid())
			{
				return tileset->GetTile(tileID);
			}
		}

		return nullptr;
	}

	void TilesetCollection::AddTileset(const std::shared_ptr<TileSet>& tileset) {
		aether::core::insert_sorted(m_tilesets, tileset, [](const std::shared_ptr<TileSet> a, const std::shared_ptr<TileSet> b) {
			return a->GetFirstGid() > b->GetFirstGid();
		});
	}
}