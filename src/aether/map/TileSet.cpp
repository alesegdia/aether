#include "aether/map/TileSet.h"
#include <cassert>

namespace aether::tilemap
{

	Tile* TileSet::GetTile(uint16_t tile_index)
	{
		tile_index = tile_index - m_gid;
		if (tile_index >= m_tiles.size())
		{
			return nullptr;
		}
		Tile& tile = m_tiles[tile_index];
		return &tile;
	}

	Tile& TileSet::AddTile(size_t index, const render::TextureRegion* tex, TileCollisionBehaviour tcb)
	{
		assert(index >= 0);
		while (m_tiles.size() <= index) {
			m_tiles.emplace_back(nullptr, TileCollisionBehaviour::Empty);
		}
		m_tiles[index] = Tile(tex, tcb);
		return m_tiles[index];
	}

	void TileSet::SetName(const std::string& name)
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

	int TileSet::GetLastGid()
	{
		return m_gid + m_tiles.size();
	}

	const math::Vec2i& TileSet::GetTileSize()
	{
		return m_tileSize;
	}

	void TileSet::SetTileSize(int w, int h)
	{
		m_tileSize.Set(w, h);
	}


}