#include "aether/map/Tile.h"

namespace aether::tilemap
{

	Tile::Tile(render::TextureRegion* texRegion, int id, TileCollisionBehaviour tcb)
		: m_texRegion(texRegion)
		, m_collisionBehaviour(tcb)
		, m_id(id)
	{

	}

}

