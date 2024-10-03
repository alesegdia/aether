#pragma once

#include <nether/nether.h>
#include <algorithm> // Add this include directive for std::min

#include "aether/render/IBatchedEntity.h"
#include "aether/render/IRenderModule.h"
#include "aether/render/Sprite.h"
#include "aether/render/Topology.h"
#include "aether/scene/SceneNode.h"
#include "aether/scene/ITilemapNode.h"
#include "aether/map/tilemap.h"

namespace aether::render
{

    class TilemapTopology
    {
    public:
        TilemapTopology(int tileSize, int partitionSize)
            : m_tileSize(tileSize), m_partitionSize(partitionSize)
        {
            // Initialize partitions based on the tilemap size and partition size
            int numPartitionsX = (m_tilemap.GetWidth() + partitionSize - 1) / partitionSize;
            int numPartitionsY = (m_tilemap.GetHeight() + partitionSize - 1) / partitionSize;
            m_partitions.resize(numPartitionsX * numPartitionsY);
        }

        void Initialize(tilemap::TileMap& tilemap)
        {
            m_tilemap = tilemap;
            CreatePartitions();
        }


        void Render(render::Camera* cam)
        {
            // Get the camera's boundary
            aether::math::Rectf cameraBoundary = cam->GetBoundary();

            // For each partition, check if it intersects with the camera boundary
            for (auto& partition : m_partitions)
            {
                // Get the partition's position and size
                int partitionX = partition.x * m_partitionSize;
                int partitionY = partition.y * m_partitionSize;
                int partitionWidth = std::min(m_partitionSize, m_tilemap.GetWidth() - partitionX);
                int partitionHeight = std::min(m_partitionSize, m_tilemap.GetHeight() - partitionY);

                // Create a rectangle representing the partition
                aether::math::Rectf partitionRect(partitionX, partitionY, partitionWidth, partitionHeight);

                // Check if the partition intersects with the camera boundary
                if (partitionRect.Intersects(cameraBoundary))
                {
                    partition.vao.Bind();
                    glDrawElements(GL_TRIANGLES, partition.indices.size(), GL_UNSIGNED_INT, 0);
                    glBindVertexArray(0);
                }
            }
        }


    private:
        struct Partition
        {
			nether::VertexArrayObject vao;
            nether::BufferObject vbo;
            nether::BufferObject ebo;
            std::vector<float> vertices;
            std::vector<unsigned int> indices;
        };

        Partition* GetPartition(int x, int y)
        {
            int partitionX = x / m_partitionSize;
            int partitionY = y / m_partitionSize;

            if (partitionX >= 0 && partitionX < m_tilemap.GetWidth() && partitionY >= 0 && partitionY < m_tilemap.GetHeight())
            {
                int index = partitionY * ((m_tilemap.GetWidth() + m_partitionSize - 1) / m_partitionSize) + partitionX;
                return &m_partitions[index];
            }

            return nullptr;
        }

        void CreatePartitions()
        {
            int numPartitionsX = (m_tilemap.GetWidth() + m_partitionSize - 1) / m_partitionSize;
            int numPartitionsY = (m_tilemap.GetHeight() + m_partitionSize - 1) / m_partitionSize;

            for (int y = 0; y < numPartitionsY; ++y)
            {
                for (int x = 0; x < numPartitionsX; ++x)
                {
                    CreatePartition(x, y);
                }
            }
        }

        void CreatePartition(int partitionX, int partitionY)
        {
            Partition partition;
            partition.vao.Generate();
            partition.vbo.Generate(nether::BufferBindingTarget::ArrayBuffer);
            partition.vbo.Generate(nether::BufferBindingTarget::ElementArrayBuffer);

            partition.vao.Bind();

            partition.vbo.Bind();
            partition.vbo.UploadBufferData(partition.vertices);

            partition.ebo.Bind();
            partition.ebo.UploadBufferData(partition.indices);

            // Assuming a simple vertex format with position and texture coordinates
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);

            glBindVertexArray(0);

            m_partitions[partitionY * ((m_tilemap.GetWidth() + m_partitionSize - 1) / m_partitionSize) + partitionX] = std::move(partition);
        }

        int m_tileSize;
        int m_partitionSize;
        tilemap::TileMap m_tilemap;
        std::vector<Partition> m_partitions;
    };


    class GLTilemapNode : public scene::SceneNode, public scene::ITilemapNode, public render::IBatchedEntity
    {
    public:
        GLTilemapNode(core::ModuleObject* o, render::ShaderProgram* shader, render::Texture* texture, tilemap::TileMap* tilemap)
            : SceneNode(o)
            , m_shader(shader)
            , m_tilemap(tilemap)
        {

        }

        render::ShaderProgram* GetShader() const override
        {
            return m_shader;
        }

        render::Texture* GetTexture() const override
        {
            return m_tilemap->GetAnyLayerTexture();
        }

		void SetLayerCell(const std::string& layer, int x, int y, int cell) override
		{
			m_tilemap->GetTileLayer(layer)->SetCell(x, y, cell);
		}

        void Draw() const override
        {

        }

		glm::mat4x4 GetEntityModel() override
        {
            return GetModel();
        }

    private:
		tilemap::TileMap* m_tilemap;
        render::ShaderProgram* m_shader;
        std::vector<render::TilemapTopology> m_mapParts;

    };


}
