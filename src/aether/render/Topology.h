// Topology.h
#pragma once

#include <vector>
#include <array>

namespace aether::render
{
    /**
     * @brief Enum representing the type of a vertex component.
     */
    enum class VertexComponentType
    {
        Position, ///< Position component
        Color,    ///< Color component
        UV        ///< UV component
    };

    /**
     * @brief Enum representing the type of a topology.
     */
    enum class TopologyType
    {
        Mesh, ///< Mesh topology
        Quad  ///< Quad topology
    };

    /**
     * @brief Struct representing a vertex component.
     */
    struct VertexComponent
    {
        VertexComponentType type; ///< Type of the vertex component
        int stride;               ///< Stride of the vertex component
        int offset;               ///< Offset of the vertex component
        int size;                 ///< Size of the vertex component
    };

    /**
     * @brief Struct representing the format of a vertex.
     */
    struct VertexFormat
    {
        std::vector<VertexComponent> components; ///< List of vertex components
    };

    /**
     * @brief Class representing a topology.
     *
     * The Topology class encapsulates the structure and organization of vertex data
     * for rendering in a graphics application. It manages the vertices, indices,
     * vertex format, and topology type, providing methods to set and retrieve these
     * attributes. The class supports different types of topologies, such as meshes
     * and quads, and allows for flexible configuration of vertex components, including
     * position, color, and UV coordinates. This abstraction facilitates the management
     * of complex vertex data and its efficient use in rendering pipelines.
     */
    class Topology
    {
    public:
        /**
         * @brief Sets the vertices.
         * @param vertices The vertices to set.
         */
        void SetVertices(const std::vector<float>& vertices);

        /**
         * @brief Sets the indices.
         * @param indices The indices to set.
         */
        void SetIndices(const std::vector<unsigned int>& indices);

        /**
         * @brief Gets the vertices.
         * @return The vertices.
         */
        const std::vector<float>& GetVertices() const;

        /**
         * @brief Gets the indices.
         * @return The indices.
         */
        const std::vector<unsigned int>& GetIndices() const;

        /**
         * @brief Gets the vertex format.
         * @return The vertex format.
         */
        const VertexFormat& GetVertexFormat() const;

        /**
         * @brief Sets the topology type.
         * @param type The topology type to set.
         */
        void SetTopologyType(TopologyType type);

        /**
         * @brief Gets the topology type.
         * @return The topology type.
         */
        TopologyType GetTopologyType() const;

		bool HasIndices() const { return !m_indices.empty(); }

    private:
        std::vector<float> m_vertices;           ///< List of vertex components
        std::vector<unsigned int> m_indices;     ///< List of indices
        VertexFormat m_vertexFormat;             ///< Vertex format
        TopologyType m_topologyType;             ///< Topology type
    };

    /**
     * @brief Creates a vertex format with 3 floats for position, 2 floats for UV, and 2 floats for color.
     * @return The created vertex format.
     */
    VertexFormat CreateP3U2C2VertexFormat();

    /**
     * @brief Creates a vertex format with 3 floats for position and 2 floats for UV.
     * @return The created vertex format.
     */
    VertexFormat CreateP3U2VertexFormat();

    /**
     * @brief Creates a vertex format with 2 floats for position and 2 floats for UV.
     * @return The created vertex format.
     */
    VertexFormat CreateP2U2VertexFormat();
}