#pragma once

#include <iostream>
#include <unordered_map>
#include <cassert>

#include <filesystem>

#include "aether/resources/iassetstorage.h"


namespace aether
{
	namespace resources
	{

		template <typename StoredAssetType>
		class BaseAssetStorage : public IAssetStorage
		{
		public:
			std::shared_ptr<StoredAssetType> GetItem(std::string path)
			{
				{
					if (m_storageMap.count(path) == 0)
					{
						return nullptr;
					}
					return m_storageMap[path];
				}
			}

			void Load(std::string path) override
			{
				m_loadMessage = path + " loaded successfully.";
				auto asset = LoadImpl(path);
				m_storageMap[path] = asset;
			}

			virtual std::shared_ptr<StoredAssetType> LoadImpl(std::string path) = 0;

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
			std::unordered_map<std::string, std::shared_ptr<StoredAssetType>> m_storageMap;
			std::string m_loadMessage;

		};


	}
}