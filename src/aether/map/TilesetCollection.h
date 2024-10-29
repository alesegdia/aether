#pragma once

#include "aether/core/utility.h"
#include <vector>
#include <memory>

namespace aether::tilemap {

    class Tile;
    class TileSet;

    class TilesetCollection {
    public:
        Tile* GetTile(int tileID);
        void AddTileset(const std::shared_ptr<TileSet>& tileset);
        const std::vector<std::shared_ptr<TileSet>>& GetTilesets() const
        {
            return m_tilesets;
        }

    private:
        std::vector<std::shared_ptr<TileSet>> m_tilesets;
    };

}