#include "Topology.h"

namespace aether::render
{

	void Topology::SetVertices(const std::vector<float>& vertices)
	{
		m_vertices = vertices;
	}

	void Topology::SetIndices(const std::vector<unsigned int>& indices)
	{
		m_indices = indices;
	}

	const std::vector<float>& Topology::GetVertices() const
	{
		return m_vertices;
	}

	const std::vector<unsigned int>& Topology::GetIndices() const
	{
		return m_indices;
	}

	const VertexFormat& Topology::GetVertexFormat() const
	{
		return m_vertexFormat;
	}

	void Topology::SetTopologyType(TopologyType type)
	{
		m_topologyType = type;
	}

	TopologyType Topology::GetTopologyType() const
	{
		return m_topologyType;
	}

	VertexFormat CreateP3U2C2VertexFormat()
	{
		VertexFormat format;
		format.components.push_back({ VertexComponentType::Position, sizeof(float) * 7, 0, 3 });
		format.components.push_back({ VertexComponentType::UV, sizeof(float) * 7, sizeof(float) * 3, 2 });
		format.components.push_back({ VertexComponentType::Color, sizeof(float) * 7, sizeof(float) * 5, 2 });
		return format;
	}

	VertexFormat CreateP3U2VertexFormat()
	{
		VertexFormat format;
		format.components.push_back({ VertexComponentType::Position, sizeof(float) * 5, 0, 3 });
		format.components.push_back({ VertexComponentType::UV, sizeof(float) * 5, sizeof(float) * 3, 2 });
		return format;
	}

	VertexFormat CreateP2U2VertexFormat()
	{
		VertexFormat format;
		format.components.push_back({ VertexComponentType::Position, sizeof(float) * 4, 0, 2 });
		format.components.push_back({ VertexComponentType::UV, sizeof(float) * 4, sizeof(float) * 2, 2 });
		return format;
	}
}