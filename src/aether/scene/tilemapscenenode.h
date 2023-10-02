#pragma once

#include "../graphics/animation.h"
#include "aether/scene/scene.h"
#include <rztl/rztl.h>

namespace aether {
    namespace scene {


        class TilemapSceneNode : public SceneNode
        {
        public:
            TilemapSceneNode(std::shared_ptr<rztl::Matrix2Di> tilemap, std::shared_ptr<graphics::Spritesheet> spritesheet, int tileSize)
				: m_tilemap(tilemap),
				  m_spritesheet(spritesheet),
				  m_tileSize(tileSize)
			{

			}

            void Render() override
            {
				for (int r = 0; r < m_tilemap->GetRowsNumberInt(); r++)
				{
					for (int c = 0; c < m_tilemap->GetColsNumberInt(); c++)
					{
						int x1, y1;
						x1 = c * m_tileSize;
						y1 = r * m_tileSize;

						int frame = m_tilemap->GetCell(c, r);

						auto bm = m_spritesheet->GetFrame(frame);
						bm->Draw(x1, y1);
					}
				}
			}

        private:
			std::shared_ptr<rztl::Matrix2Di> m_tilemap;
			std::shared_ptr<graphics::Spritesheet> m_spritesheet;
			int m_tileSize = 0;

        };


    }
}
