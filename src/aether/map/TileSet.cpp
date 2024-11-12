#include "aether/map/TileSet.h"
#include <cassert>
#include "aether/core/Engine.h"
#include "aether/render/IRenderModule.h"

namespace aether::tilemap
{
	TileSet::TileSet(const Tmx::Tileset& tmxTileset, const std::string& basePath)
		: m_gid(0)
	{
		SetName(tmxTileset.GetName());
		SetTileSize(tmxTileset.GetTileWidth(), tmxTileset.GetTileHeight());
		SetFirstGid(tmxTileset.GetFirstGid());

		// Load texture for the tileset
		auto path = basePath + "/" + tmxTileset.GetImage()->GetSource();
		render::Texture* t = aether::GEngine->GetRenderModuleAccessor()->LoadTextureFromFile(path);

		// Create spritesheet for the tileset
		m_columns = tmxTileset.GetImage()->GetWidth() / tmxTileset.GetTileWidth();
		m_rows = tmxTileset.GetImage()->GetHeight() / tmxTileset.GetTileHeight();
		m_spritesheet = std::make_shared<render::Spritesheet>(m_columns, m_rows, t);

		for (int i = 0; i < m_columns * m_rows; i++)
		{
			aether::render::TextureRegion* region = m_spritesheet->GetFrame(i);
			Tile newTile(region, i);
			m_tiles.emplace_back(newTile);
		}

		// Add tiles to the tileset
		for (auto tmxTile : tmxTileset.GetTiles())
		{
			TileCollisionBehaviour collisionBehaviour = TileCollisionBehaviour::Empty;
			if (tmxTile->GetProperties().HasProperty("collision"))
			{
				auto collisionType = tmxTile->GetProperties().GetStringProperty("collision");

				if (collisionType == "solid")
				{
					collisionBehaviour = TileCollisionBehaviour::Solid;
				}
				else if (collisionType == "oneway")
				{
					collisionBehaviour = TileCollisionBehaviour::Oneway;
				}
				else if (collisionType == "empty")
				{
					collisionBehaviour = TileCollisionBehaviour::Empty;
				}
			}
			
			// std::array<float, 4> texCoords = newSheet->GetTextureRegion(tmxTile->GetId()).GetTexCoords();

			auto tileIndex = tmxTile->GetId();
			auto& aetherTile = m_tiles[tileIndex];

			aetherTile.SetCollisionBehaviour(collisionBehaviour);

			// Copy properties from the tile
			for (auto prop : tmxTile->GetProperties().GetList())
			{
				aetherTile.AddProperty(prop.first, prop.second);
			}
		}
	}

	Tile* TileSet::GetTile(uint16_t tile_index)
	{
		return &m_tiles[tile_index];
	}

	void TileSet::SetName(const std::string& name)
	{
		m_name = name;
	}

	void TileSet::SetFirstGid(int gid)
	{
		m_gid = gid;
	}

	int TileSet::GetFirstGid()
	{
		return m_gid;
	}

	int TileSet::GetLastGid()
	{
		return m_gid + m_tiles.size();
	}

	const math::Vec2i& TileSet::GetTileSize()
	{
		return m_tileSize;
	}

	void TileSet::SetTileSize(int w, int h)
	{
		m_tileSize.Set(w, h);
	}

}