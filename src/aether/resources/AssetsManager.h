#pragma once

#include <iostream>
#include <unordered_map>
#include <cassert>

#include <filesystem>

#include "aether/resources/iassetstorage.h"
#include "aether/resources/baseassetstorage.h"


namespace aether
{
	namespace resources
	{

		class AssetsManager
		{
		public:
			AssetsManager();

			void LoadFolder(const char* path);

			template <typename T>
			std::shared_ptr<T> GetAsset(std::string path)
			{
				auto file_extension = std::filesystem::path(path).extension().generic_string();
				if (m_storages.count(file_extension) == 0)
				{
					return nullptr;
				}
				auto storage_iface = m_storages[file_extension];
				auto storage = std::static_pointer_cast<BaseAssetStorage<T>>(storage_iface);
				return storage->GetItem(path);
			}
			
			void AddStorage(std::string extension, std::shared_ptr<IAssetStorage> storage);
			
		private:
			std::string GetExt(std::string path);
			std::string GetExt(std::filesystem::directory_entry dir);

			std::unordered_map<std::string, std::shared_ptr<IAssetStorage>> m_storages;
			std::string m_basePath;

		};


	}
}