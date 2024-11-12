#include "GLTilemap.h"
#include "GLResources.h"

#include <vector>
#include <string>
#include <memory>

#include <set>
#include <glm/mat4x4.hpp>
#include <algorithm>

#include <nether/nether.h>
#include "aether/render/IRenderModule.h"
#include "aether/render/camera.h"
#include "aether/render/gl/GLShaderProgram.h"

namespace aether::render
{

	TilemapTopology::TilemapTopology(std::shared_ptr<tilemap::TileMap> tilemap, int partitionSize)
		: m_tilemap(tilemap)
		, m_partitionSize(partitionSize)
	{
		auto mapWidth  = tilemap->GetWidthInTiles();
		auto mapHeight = tilemap->GetHeightInTiles();

		for (int i = 0; i < tilemap->GetTileLayers().size(); i++)
		{
			auto layer = tilemap->GetTileLayer(i);
			LayerData data;

			// Initialize partitions based on the tilemap size and partition size
			m_numPartitions.x = (m_tilemap->GetWidthInTiles() + partitionSize - 1) / partitionSize;
			m_numPartitions.y = (m_tilemap->GetHeightInTiles() + partitionSize - 1) / partitionSize;

			for (int y = 0; y < m_numPartitions.y; ++y)
			{
				for (int x = 0; x < m_numPartitions.x; ++x)
				{
					int x0 = x * partitionSize;
					int y0 = y * partitionSize;
					int x1 = x0 + partitionSize;
					int y1 = y0 + partitionSize;
					data.layerPartitions.push_back(CreatePartition(layer.get(), x0, y0, x1, y1));
				}
			}

			data.layerPartitions.resize(m_numPartitions.x * m_numPartitions.y);
			m_layers.push_back(data);
		}
	}

	TilemapTopology::Partition TilemapTopology::CreatePartition(tilemap::TileLayer* layer, int x0, int y0, int x1, int y1)
	{
		std::vector<float> vertices;
		std::vector<unsigned int> indices;

		int tileWidth = m_tilemap->GetTileWidth();
		int tileHeight = m_tilemap->GetTileHeight();

		for (int tileY = y0; tileY < y1; tileY++)
		{
			for (int tileX = x0; tileX < x1; tileX++)
			{
				if (tileX >= m_tilemap->GetWidthInTiles() || tileY >= m_tilemap->GetHeightInTiles())
					continue;

				auto tile = layer->GetTileInstance(tileX, tileY);
				if (tile == nullptr)
					continue;

				auto tileset = m_tilemap->GetTileset(tile->tilesetId);
				auto tilesetTile = tileset->GetTile(tile->id);

				float left = tileX * tileWidth;
				float right = left + tileWidth;
				float top = tileY * tileHeight;
				float bottom = top + tileHeight;

				// Get UV coordinates from the tilemap's first layer
				auto uvCoords = tilesetTile->GetTexCoords();

				// Add vertices for the tile (position and texture coordinates)
				vertices.insert(vertices.end(), {
					left, top, 0.0f, uvCoords[0], uvCoords[0],
					right, top, 0.0f, uvCoords[1], uvCoords[1],
					right, bottom, 0.0f, uvCoords[2], uvCoords[2],
					left, bottom, 0.0f, uvCoords[3], uvCoords[3]
				});

				// Calculate the base index for the current tile
				unsigned int baseIndex = (tileY * m_partitionSize + tileX) * 4;

				// Add indices for the two triangles that make up the tile
				indices.insert(indices.end(), {
					baseIndex, baseIndex + 1, baseIndex + 2,
					baseIndex, baseIndex + 2, baseIndex + 3
				});
			}
		}

		TilemapTopology::Partition partition;
		partition.x = x0 * m_tileSize.x;
		partition.y = y0 * m_tileSize.y;
		partition.vao.Generate();
		partition.vbo.Generate(nether::BufferBindingTarget::ArrayBuffer);
		partition.ebo.Generate(nether::BufferBindingTarget::ElementArrayBuffer);

		partition.vao.Bind();

		partition.vbo.Bind();
		partition.vbo.UploadBufferData(partition.vertices);

		partition.ebo.Bind();
		partition.ebo.UploadBufferData(partition.indices);

		// TODO: pasar a actuar sobre el partition.vao en vez de usar opengl del tiron
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glBindVertexArray(0);
		return partition;
	}

	void TilemapTopology::Render(render::Camera* cam)
	{

		// Get the camera's boundary
		// aether::math::Rectf cameraBoundary = cam->GetBoundary();

		// For each partition, check if it intersects with the camera boundary

		for (auto& layer : m_layers)
		{
			for (auto& partition : layer.layerPartitions)
			{
				// Get the partition's position and size
				int partitionX = partition.x;
				int partitionY = partition.y;
				int partitionWidth  = std::min<int>(m_partitionSize, m_tilemap->GetTileWidth()  * m_tilemap->GetWidthInTiles()  - partitionX);
				int partitionHeight = std::min<int>(m_partitionSize, m_tilemap->GetTileHeight() * m_tilemap->GetHeightInTiles() - partitionY);

				// Create a rectangle representing the partition
				aether::math::Rectf partitionRect(partitionX, partitionY, partitionWidth, partitionHeight);

				// Check if the partition intersects with the camera boundary
				if (true) // partitionRect.Intersects(cameraBoundary))
				{
					partition.vao.Bind();
					glDrawElements(GL_TRIANGLES, partition.indices.size(), GL_UNSIGNED_INT, 0);
					partition.vao.Unbind();
				}
			}
		}
	}

	GLTilemapNode::GLTilemapNode(core::ModuleObject* o, render::ShaderProgram* shader, const std::shared_ptr<tilemap::TileMap>& map)
		: scene::ITilemapNode(o)
		, m_shader(shader)
		, m_tilemap(map)
		, m_topology(map, 4)
	{
		SetTextureConfigToTilemap();
	}

	void GLTilemapNode::SetTextureConfigToTilemap()
	{
		m_textureConfig = {};

		m_textureConfig.AddEntrySorted(0, m_tilemap->GetTileset(0)->GetTexture());
		/*

		// Create a texture config for the tilemap
		std::set<render::Texture*> textures;
		
		auto tsc = m_tilemap->GetTilesetCollection();
		for (auto& tileset : tsc->GetTilesets())
		{
			textures.insert(tileset->GetTexture());
		}
		
		for (auto texture : textures)
		{
			m_textureConfig.AddEntrySorted(0, texture);
		}
		*/
	}

	render::ShaderProgram* GLTilemapNode::GetShader() const
	{
		return m_shader;
	}

	render::TextureConfig GLTilemapNode::GetTextureConfig() const
	{
		return m_textureConfig;
	}

	void GLTilemapNode::SetLayerCell(const std::string& layer, int x, int y, int cell)
	{
		// m_tilemap->GetTileLayer(layer)->SetCell(x, y, cell);
	}

	void GLTilemapNode::Draw()
	{
		auto glshader = ResourceCast(m_shader);
		auto model = GetModel();
		glshader->SetMat4Uniform("model", model);
		m_topology.Render(nullptr);
	}


}