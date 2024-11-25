#pragma once

#include <iostream>
#include <map>
#include <cassert>
#include <filesystem>
#include <regex>

#include "aether/resources/iassetstorage.h"

namespace aether
{
	namespace resources
	{

		template <typename StoredAssetType>
		class BaseAssetStorage : public IAssetStorage
		{
		public:
			~BaseAssetStorage()
			{
				for (auto item : m_storageMap)
				{
					delete item.second;
				}
			}

			StoredAssetType* GetItem(std::string path)
			{
				path = NormalizePath(path);

				if (m_storageMap.count(path) == 0)
				{
					return nullptr;
				}
				auto item = m_storageMap[path];
				return item;
			}

			void Load(std::string path) override
			{
				path = NormalizePath(path);

				m_loadMessage = path + " loaded successfully.";
				auto asset = LoadImpl(path);
				m_storageMap[path] = asset;
			}

			virtual StoredAssetType* LoadImpl(std::string path) = 0;

			std::string GetLoadMessage() override
			{
				return m_loadMessage;
			}

		protected:
			void SetLoadMessage(std::string msg)
			{
				m_loadMessage = msg;
			}

		private:
			std::map<std::string, StoredAssetType*> m_storageMap;
			std::string m_loadMessage;

			std::string NormalizePath(const std::string& path)
			{
				std::string normalizedPath = std::regex_replace(path, std::regex("/+"), "/");
				return normalizedPath;
			}
		};

	}
}