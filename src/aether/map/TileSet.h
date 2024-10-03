#pragma once

#include "aether/map/Tile.h"


namespace aether {
    namespace tilemap {


        class TileSet
        {
        public:
            using Shared = std::shared_ptr<TileSet>;

            Tile* GetTile(uint16_t tile_index);

            Tile& AddTile(size_t index, const render::TextureRegion* tex, TileCollisionBehaviour tcb);

            void SetName(const std::string& name);

            void SetFirstGid(int gid);

            int GetFirstGid();

            const math::Vec2i& GetTileSize();

            void SetTileSize(int w, int h);

        private:
            std::vector<Tile> m_tiles;
            std::string m_name;
            int m_gid;
            aether::math::Vec2i m_tileSize;

        };



    }
}
