#pragma once

#include <iostream>
#include <unordered_map>
#include <cassert>

#include "aether/graphics/texture.h"
#include "aether/graphics/font.h"

#include <filesystem>


namespace aether
{
	namespace resources
	{

		class IAssetStorage
		{
		public:
			virtual ~IAssetStorage() = default;

			virtual void Load(std::string path) = 0;
			virtual std::string GetLoadMessage() = 0;
		};

		template <typename StoredAssetType>
		class BaseAssetStorage : public IAssetStorage
		{
		public:
			std::shared_ptr<StoredAssetType> GetItem(std::string path);

			void Load(std::string path) override;

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

		template <typename StoredAssetType>
		std::shared_ptr<StoredAssetType> aether::resources::BaseAssetStorage<StoredAssetType>::GetItem(std::string path)
		{
			if (m_storageMap.count(path) == 0)
			{
				return nullptr;
			}
			return m_storageMap[path];
		}

		template <typename StoredAssetType>
		void aether::resources::BaseAssetStorage<StoredAssetType>::Load(std::string path)
		{
			m_loadMessage = path + " loaded successfully.";
			auto asset = LoadImpl(path);
			m_storageMap[path] = asset;
		}

		class TextureAssetManager : public BaseAssetStorage<aether::graphics::Texture>
		{
		public:
			std::shared_ptr<aether::graphics::Texture> LoadImpl(std::string path) override;

		};

		class FontAssetManager : public BaseAssetStorage<aether::graphics::Font>
		{
		public:
			std::shared_ptr<aether::graphics::Font> LoadImpl(std::string path) override;
		};

		class AssetsManager
		{
		public:
			AssetsManager();

			void LoadFolder(const char* path);

			template <typename T>
			std::shared_ptr<T> GetAsset(std::string path);
			
			void AddStorage(std::string extension, std::shared_ptr<IAssetStorage> storage);
			
		private:
			std::string GetExt(std::string lepath);
			std::filesystem::path GetExt()
			{
				return std::filesystem::path{  };
			}

			std::unordered_map<std::string, std::shared_ptr<IAssetStorage>> m_storages;
			std::string m_basePath;

		};

		template <typename T>
		std::shared_ptr<T>
			aether::resources::AssetsManager::GetAsset(std::string path)
		{
			auto file_extension = std::filesystem::path(path).extension();
			auto storage_iface = m_storages[file_extension];
			auto storage = std::static_pointer_cast<BaseAssetStorage<T>>(storage_iface);
			return storage->GetItem(path);
		}

	}
}