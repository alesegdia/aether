#pragma once

#include "aether/map/Tile.h"
#include "aether/render/Spritesheet.h"
#include <glm/glm.hpp>

#include <Tmx.h>

namespace aether {
    namespace tilemap {

        class TileSet
        {
        public:
            using Shared = std::shared_ptr<TileSet>;

            TileSet(const Tmx::Tileset& tmxTileset, const std::string& basePath);

            Tile* GetTile(uint16_t tile_index);

            void SetSizeInTiles(const glm::fvec2& size)
            {
				m_sizeInTiles = size;
            }

            void SetName(const std::string& name);

            void SetFirstGid(int gid);

            int GetFirstGid();
            int GetLastGid();

            const math::Vec2i& GetTileSize();

            void SetTileSize(int w, int h);

            aether::render::Texture* GetTexture()
            {
                return m_spritesheet->GetTexture();
            }

			int GetColumns() const
			{
				return m_columns;
			}

			int GetRows() const
			{
				return m_rows;
			}

        private:
            std::vector<Tile> m_tiles;
            std::string m_name;
            int m_gid;
            aether::math::Vec2i m_tileSize;
			glm::fvec2 m_sizeInTiles;
            int m_columns;
            int m_rows;
			std::shared_ptr<render::Spritesheet> m_spritesheet;

        };



    }
}
