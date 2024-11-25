#include "aether/resources/AssetsManager.h"

#include "asepriteanimstorage.h"
#include "sheetassetstorage.h"
#include "aether/resources/textureassetstorage.h"
#include "aether/resources/fontassetstorage.h"

#include "aether/core/utility.h"
#include "aether/core/logger.h"

namespace aether
{
	namespace resources
	{

		AssetsManager::AssetsManager()
		{
			AddStorage(".font", std::make_shared<FontAssetStorage>());
			AddStorage(".png", std::make_shared<TextureAssetStorage>());
			//AddStorage(".json", std::make_shared<AsepriteAnimStorage>());
			AddStorage(".sheet", std::make_shared<SheetAssetStorage>());
		}

		std::string AssetsManager::GetExt(std::string path)
		{
			auto ext = std::filesystem::path(path).extension().generic_string();
			return aether::core::to_lower(ext);
		}

		std::string AssetsManager::GetExt(std::filesystem::directory_entry dir)
		{
			auto ext = std::filesystem::path(dir).extension().generic_string();
			return aether::core::to_lower(ext);
		}

		void AssetsManager::LoadFolder(const char* path)
		{
			assert(ValidatePath(path));
			using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

			try
			{
				Logger::LogMsg() << "Scanning " << std::string(path) << " for assets...";
				for (const auto& dirEntry : recursive_directory_iterator(path))
				{
					auto ext = GetExt(dirEntry);
					Logger::LogMsg() << "Loading " << dirEntry << " with extension " << ext << "...";
					if (m_storages.count(ext) == 0)
					{
						Logger::LogWarning() << "There is no storage for extension \"" << ext << "\" so " << dirEntry << " won't be loaded.";
					}
					else
					{
						m_storages[ext]->Load(dirEntry.path().generic_string());
						Logger::LogMsg() << m_storages[ext]->GetLoadMessage();
					}
				}

			}
			catch (std::filesystem::filesystem_error& e)
			{
				Logger::LogError() << "Trying to scan an invalid path: " << e.path1();
			}

		}

		void AssetsManager::AddStorage(std::string extension, std::shared_ptr<IAssetStorage> storage)
		{
			assert(m_storages.count(extension) == 0);
			extension = aether::core::to_lower(extension);
			m_storages[extension] = storage;
		}


	}
}