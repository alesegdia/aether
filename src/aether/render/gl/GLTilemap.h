#pragma once


#include "aether/map/tilemap.h"
#include "aether/scene/ITilemapNode.h"
#include "aether/scene/SceneNode.h"
#include "aether/render/IBatchedEntity.h"

#include <nether/nether.h>

namespace aether::core {
	class ModuleObject;
}

namespace aether::render {
	class ShaderProgram;
	class Texture;
	class Camera;
}

namespace aether::tilemap {
	class TileMap;
}


namespace aether::render {

	class TilemapTopology {
	public:
		TilemapTopology(int tileSize, int partitionSize);

		void Initialize(tilemap::TileMap& tilemap);
		void Render(render::Camera* cam);

	private:
		struct Partition {
			nether::VertexArrayObject vao;
			nether::BufferObject vbo;
			nether::BufferObject ebo;
			std::vector<float> vertices;
			std::vector<unsigned int> indices;
			int x, y;
		};

		Partition* GetPartition(int x, int y);
		void CreatePartitions();
		void CreatePartition(int partitionX, int partitionY);

		int m_tileSize;
		int m_partitionSize;
		tilemap::TileMap m_tilemap;
		std::vector<Partition> m_partitions;
	};

	class GLTilemapNode : public scene::SceneNode, public scene::ITilemapNode, public render::IBatchedEntity {
	public:
		GLTilemapNode(core::ModuleObject* o, render::ShaderProgram* shader, tilemap::TileMap* tilemap);

		render::ShaderProgram* GetShader() const override;
		render::TextureConfig GetTextureConfig() const override;
		void SetLayerCell(const std::string& layer, int x, int y, int cell) override;
		void Draw() override;
		glm::mat4x4 GetEntityModel() override;


	private:

		void SetTextureConfigToTilemap();

		tilemap::TileMap* m_tilemap;
		render::ShaderProgram* m_shader;
		std::vector<render::TilemapTopology> m_mapParts;
		TextureConfig m_textureConfig;
	};

}