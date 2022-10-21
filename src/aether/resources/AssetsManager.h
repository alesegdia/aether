#pragma once

#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <cassert>

#include "aether/graphics/texture.h"
#include "aether/graphics/font.h"

namespace aether
{
	namespace resources
	{

		class IAssetStorage
		{
		public:
			virtual ~IAssetStorage() = default;

			virtual void Load(std::string path) = 0;
		};

		template <typename StoredAssetType>
		class BaseAssetStorage : public IAssetStorage
		{
		public:
			std::shared_ptr<StoredAssetType> GetItem(std::string path)
			{
				if (m_storageMap.count(path) == 0)
				{
					return nullptr;
				}
				return m_storageMap[path];
			}

			void Load(std::string path) override
			{
				auto asset = LoadImpl(path);
				m_storageMap[path] = asset;
			}

			virtual std::shared_ptr<StoredAssetType> LoadImpl(std::string path) = 0;

		private:
			std::unordered_map<std::string, std::shared_ptr<StoredAssetType>> m_storageMap;

		};

		class TextureAssetManager : public BaseAssetStorage<aether::graphics::Texture>
		{
		public:
			std::shared_ptr<aether::graphics::Texture> LoadImpl(std::string path) override
			{
				auto texture = std::make_shared<graphics::Texture>();
				texture->Load(path.c_str());
				return texture;
			}
		};

		class FontAssetManager : public BaseAssetStorage<aether::graphics::Font>
		{
		public:
			std::shared_ptr<aether::graphics::Texture> LoadImpl(std::string path) override
			{
				auto font = std::make_shared<graphics::Font>();
				font->Load(path.c_str());
				return font;
			}
		};

		class AssetsManager
		{
		public:
			AssetsManager()
			{

			}

			void LoadFolder(const char* path)
			{
				using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

				for (const auto& dirEntry : recursive_directory_iterator(path))
				{
					std::cout << dirEntry << std::endl;
					std::cout << GetExtension(dirEntry) << std::endl;
				}
			}

			template <typename T>
			std::shared_ptr<T> GetAsset(std::string path)
			{
				auto file_extension = GetExtension(path);
				auto storage_iface = m_storages[file_extension];
				auto storage = std::static_pointer_cast<BaseAssetStorage<T>>(storage_iface);
				return storage->GetItem(path);
			}
			
			void AddStorage(std::string extension, std::shared_ptr<IAssetStorage> storage)
			{
				assert(m_storages.count(extension) == 0);
				m_storages[extension] = storage;
			}

		private:
			std::filesystem::path GetExtension(std::string path)
			{
				return std::filesystem::path(path.c_str()).extension();
			}

			std::filesystem::path GetExtension(std::filesystem::directory_entry entry)
			{
				return std::filesystem::path(entry).extension();
			}

			std::unordered_map<std::string, std::shared_ptr<IAssetStorage>> m_storages;

		};

	}
}