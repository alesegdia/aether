#include "aether/map/Tile.h"

// Implementation for aether/map/Tile
namespace aether::tilemap
{


	Tile::Tile(const render::TextureRegion* tex, TileCollisionBehaviour tcb)
		: texture(tex),
		collisionBehaviour(tcb)
	{

	}


}

