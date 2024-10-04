#include "aether/map/Tile.h"

namespace aether::tilemap
{

	Tile::Tile(const render::TextureRegion* tex, TileCollisionBehaviour tcb)
		: texture(tex),
		collisionBehaviour(tcb)
	{

	}

}

