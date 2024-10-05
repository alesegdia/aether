#pragma once

#include "aether/map/TileSet.h"
#include "aether/map/TileLayer.h"
#include "aether/map/ObjectLayer.h"
#include "aether/core/utility.h"
#include "aether/render/Spritesheet.h"

#include <vector>
#include <functional>

#include <Tmx.h>


class IRenderModule;

namespace aether {
	namespace tilemap {

		template <typename ResourceType>
		class ResourceStore {
		public:

			using SharedRes = std::shared_ptr<ResourceType>;

			template <typename... Args>
			const SharedRes& Create(const std::string& id, Args... args)
			{
				m_storage[id] = std::make_shared<ResourceType>(args...);
				return m_storage[id];
			}

			const SharedRes& Get(const std::string& id)
			{
				if (m_storage.count(id) == 0) {
					m_storage[id] = nullptr;
				}
				return m_storage[id];
			}

		private:
			std::unordered_map<std::string, std::shared_ptr<ResourceType>> m_storage;
		};


		class TileMap
		{
		public:

			TileMap()
			{
				m_tilesetCollection = std::make_shared<TilesetCollection>();
			}

			void AddSheet(const std::shared_ptr<aether::render::Spritesheet>& sheet);

			void AddTileset(const TileSet::Shared& tileset);

			void AddTileLayer(const TileLayer::Shared& tilelayer);

			void AddObjectLayer(const ObjectLayer::Shared& objectLayer);

			aether::math::Vec2i GetObjectTilePosition(const ObjectLayer::Object& object);

			template<typename LayerType>
			void AddLayer(std::shared_ptr<LayerType> layer)
			{
				static_assert(std::is_base_of<Layer, LayerType>::value);
				m_layers.push_back(std::static_pointer_cast<Layer>(layer));
			}

			TileLayer::Shared GetTileLayer(const std::string& layerId);

			ObjectLayer::Shared GetObjectLayer(const std::string& layerId);

			TileSet::Shared GetTileset(int i);

			std::unordered_map<std::string, TileLayer::Shared>& GetTileLayers();

			void SetBasePath(const std::string& basePath);

			const std::string& GetBasePath();

			float GetWidth() const
			{
				assert(!m_layers.empty() && "must have some tile layer to fetch width");
				const auto& layer = *(*(m_tileLayers.begin())).second;
				return float(layer.GetMapWidth() * layer.GetTileWidth());
			}

			float GetHeight() const
			{
				assert(!m_layers.empty() && "must have some tile layer to fetch height");
				const auto& layer = *(*(m_tileLayers.begin())).second;
				return float(layer.GetMapHeight() * layer.GetTileHeight());
			}

			/*
			Texture* GetAnyTilesetTexture()
			{
				assert(!m_tilesets.empty() && "must have some tileset to fetch texture");
				return m_tilesets[0]->GetTexture();
			}
			*/

		private:
			std::vector<Layer::Shared> m_layers;
			std::vector<TileSet::Shared> m_tilesets;
			std::shared_ptr<TilesetCollection> m_tilesetCollection;
			std::vector<std::shared_ptr<render::Spritesheet>> m_sheetStore;
			std::unordered_map<std::string, TileLayer::Shared> m_tileLayers;
			std::unordered_map<std::string, ObjectLayer::Shared> m_objectLayers;
			std::string m_basePath;

		};


		std::shared_ptr<TileMap> BuildMap(const Tmx::Map& inmap, aether::render::IRenderModule* module);


	}
}
