#pragma once


#include <rztl/rztl.h>

#include "aether/graphics/animation.h"

#include "aether/scene/SceneNode.h"
#include "aether/map/tilemap.h"

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

						if (frame != 89)
						{
							auto bm = m_spritesheet->GetFrame(frame);
							bm->Draw(float(x1), float(y1));
						}
					}
				}
			}

		private:
			std::shared_ptr<rztl::Matrix2Di> m_tilemap;
			std::shared_ptr<graphics::Spritesheet> m_spritesheet;
			int m_tileSize = 0;

		};


		class TiledTilemapSceneNode : public SceneNode
		{
		public:
			TiledTilemapSceneNode(std::shared_ptr<aether::tilemap::TileMap> tilemap)
				: m_tilemap(tilemap)
			{

			}

			void Render() override
			{
				m_tilemap->Render();
			}

		private:
			std::shared_ptr<aether::tilemap::TileMap> m_tilemap;

		};


    }
}
