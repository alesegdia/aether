#pragma once

#include <array>
#include <unordered_map>
#include "aether/render/TextureRegion.h"

namespace aether::tilemap {


    enum class TileCollisionBehaviour : uint8_t
    {
        Empty = 0,
        Solid,
        Oneway
    };

    struct Tile
    {
        Tile(render::TextureRegion* texRegion, int id, TileCollisionBehaviour tcb = TileCollisionBehaviour::Empty);

        int GetID()
		{
			return m_id;
        }

        void AddProperty(const std::string& key, const std::string& value)
        {
			m_props[key] = value;
        }

        uvs_t GetTexCoords()
        {
			return m_texRegion->GetUVs();
        }

        TileCollisionBehaviour GetCollisionBehaviour()
        {
            return m_collisionBehaviour;
        }

		void SetCollisionBehaviour(TileCollisionBehaviour tcb)
		{
			m_collisionBehaviour = tcb;
		}

    private:
        int m_id = -1;
        render::TextureRegion* m_texRegion;
        TileCollisionBehaviour m_collisionBehaviour = TileCollisionBehaviour::Empty;
        std::unordered_map<std::string, std::string> m_props;
    };

}
