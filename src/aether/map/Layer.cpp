#include "aether/map/Layer.h"

namespace aether::tilemap
{


	Layer::Layer(const std::string& id, int zOrder)
	{
		m_name = id;
		m_depthOrder = zOrder;
	}

	Layer::~Layer() = default;

	const std::string& Layer::GetName()
	{
		return m_name;
	}

	int Layer::GetDepthOrder() const
	{
		return m_depthOrder;
	}



}