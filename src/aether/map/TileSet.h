#pragma once

#include "aether/map/Tile.h"
#include "aether/render/Spritesheet.h"


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

            void SetSpritesheet(std::shared_ptr<render::Spritesheet> sheet)
            {
				m_spritesheet = sheet;
            }

            int GetFirstGid();
            int GetLastGid();

            const math::Vec2i& GetTileSize();

            void SetTileSize(int w, int h);

            aether::render::Texture* GetTexture()
            {
                return m_spritesheet->GetTexture();
            }

        private:
            std::vector<Tile> m_tiles;
            std::string m_name;
            int m_gid;
            aether::math::Vec2i m_tileSize;
			std::shared_ptr<render::Spritesheet> m_spritesheet;

        };



    }
}
