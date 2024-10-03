#pragma once

#include "aether/map/Layer.h"
#include "aether/math/Rect.h"
#include <unordered_map>

namespace aether::tilemap
{

	class ObjectLayer : public Layer {
	public:

		struct Object {
			std::string name;
			math::Recti aabb;
			std::unordered_map<std::string, std::string> props;
		};

		using Shared = std::shared_ptr<ObjectLayer>;

		ObjectLayer(const std::string& id, int zOrder);

		Object& CreateNewObject(const std::string& name, int x, int y, int w, int h);

		const std::vector<Object>& GetAllObjects() const;

		void ForEachObject(std::function<void(const Object&)> callback)
		{
			for (const auto& object : m_objects)
			{
				callback(object);
			}
		}

		void Render() override;

	private:
		std::vector<Object> m_objects;

	};


}