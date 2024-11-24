#pragma once

#include <iostream>
#include <unordered_map>
#include <cassert>

#include <filesystem>

#include <regex>

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
			void LoadFolder(const std::string& paths)
			{
				LoadFolder(paths.c_str());
			}

			template <typename T>
			T* GetAsset(std::string path)
			{
				auto file_extension = GetExt(path);
				if (m_storages.count(file_extension) == 0)
				{
					return nullptr;
				}
				auto storage_iface = m_storages[file_extension];
				auto storage = std::static_pointer_cast<BaseAssetStorage<T>>(storage_iface);
				auto item = storage->GetItem(path);
				return item;
			}
			
		private:
			void AddStorage(std::string extension, std::shared_ptr<IAssetStorage> storage);

			bool ValidatePath(const char* path)
			{
				std::string strpath = path;
				char lastChar = strpath[strpath.length() - 1];
				char preLastChar = strpath[strpath.length() - 2];
				if (lastChar == '/' && preLastChar != '/') return true;
				return false;
			}

			std::string GetExt(std::string path);
			std::string GetExt(std::filesystem::directory_entry dir);

			std::unordered_map<std::string, std::shared_ptr<IAssetStorage>> m_storages;

		};


	}
}