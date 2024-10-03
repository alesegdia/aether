#include "aether/map/ObjectLayer.h"

namespace aether::tilemap
{


	ObjectLayer::ObjectLayer(const std::string& id, int zOrder)
		: Layer(id, zOrder)
	{

	}

	ObjectLayer::Object& ObjectLayer::CreateNewObject(const std::string& name, int x, int y, int w, int h)
	{
		Object object;
		object.name = name;
		object.aabb = { x, y, w, h };
		m_objects.push_back(object);
		return m_objects.back();
	}

	const std::vector<ObjectLayer::Object>& ObjectLayer::GetAllObjects() const
	{
		return m_objects;
	}

	void ObjectLayer::Render()
	{

	}


}