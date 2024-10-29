#pragma once

#include "aether/map/tilemap.h"
#include "aether/scene/SceneNode.h"
// Header for aether/scene/ITilemapNode

namespace aether::scene
{
	

	class ITilemapNode : public SceneNode
	{
	public:
		virtual ~ITilemapNode() = default;

		
		virtual void SetLayerCell(const std::string& layer, int x, int y, int tile) = 0;

	};


}