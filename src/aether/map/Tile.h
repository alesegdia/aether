#pragma once

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
        Tile(const render::TextureRegion* tex, TileCollisionBehaviour tcb);

        const render::TextureRegion* texture;
        TileCollisionBehaviour collisionBehaviour = TileCollisionBehaviour::Empty;
        std::unordered_map<std::string, std::string> props;
    };

}
