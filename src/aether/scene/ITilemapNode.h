#pragma once

#include "aether/map/tilemap.h"
// Header for aether/scene/ITilemapNode

namespace aether::scene
{
	

	class ITilemapNode
	{
	public:
		virtual ~ITilemapNode() = default;

		
		virtual void SetLayerCell(int layer, int x, int y, int tile) = 0;

	};


}