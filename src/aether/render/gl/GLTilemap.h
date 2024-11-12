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
		TilemapTopology(std::shared_ptr<tilemap::TileMap>, int partitionSize);

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

		struct LayerData {
			std::vector<Partition> layerPartitions;
		};

		Partition* GetPartition(int x, int y);
		Partition CreatePartition(tilemap::TileLayer* layer, int x0, int y0, int x1, int y1);

		glm::fvec2 m_tileSize;
		int m_partitionSize;
		glm::ivec2 m_numPartitions;
		std::vector<LayerData> m_layers;
		std::shared_ptr<tilemap::TileMap> m_tilemap;
	};

	class GLTilemapNode : public scene::ITilemapNode, public render::IBatchedEntity {
	public:
		GLTilemapNode(core::ModuleObject* o, render::ShaderProgram* shader, const std::shared_ptr<tilemap::TileMap>& map);

		render::ShaderProgram* GetShader() const override;
		render::TextureConfig GetTextureConfig() const override;
		void SetLayerCell(const std::string& layer, int x, int y, int cell) override;
		void Draw() override;


	private:

		void SetTextureConfigToTilemap();

		std::shared_ptr<tilemap::TileMap> m_tilemap;
		render::ShaderProgram* m_shader;
		TilemapTopology m_topology;
		TextureConfig m_textureConfig;
	};

}