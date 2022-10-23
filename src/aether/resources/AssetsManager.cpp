#include "AssetsManager.h"

namespace aether
{
	namespace resources
	{

		AssetsManager::AssetsManager()
		{
			AddStorage(".font", std::make_shared<FontAssetManager>());
			AddStorage(".png", std::make_shared<TextureAssetManager>());
		}

		std::string AssetsManager::GetExt(std::string lepath)
		{
			std::wstring ext = std::filesystem::path(lepath).extension().c_str();
			std::string sext(ext.begin(), ext.end());
			return sext;
		}

		void AssetsManager::LoadFolder(const char* path)
		{
			
			using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

			for (const auto& dirEntry : recursive_directory_iterator(path))
			{
				auto pathString = dirEntry.path().generic_string();
				auto ext = GetExt(pathString);
				std::cout << "Loading " << dirEntry << " with extension " << ext << "..." << std::endl;
				if (m_storages.count(ext) == 0)
				{
					std::cout << "There is no storage for extension \"" << ext << "\"." << std::endl;
				}
				else
				{
					m_storages[ext]->Load(pathString);
					std::cout << m_storages[ext]->GetLoadMessage() << std::endl;
				}
				std::cout << std::endl;
			}
		}

		void AssetsManager::AddStorage(std::string extension, std::shared_ptr<IAssetStorage> storage)
		{
			assert(m_storages.count(extension) == 0);
			m_storages[extension] = storage;
		}


		std::shared_ptr<aether::graphics::Texture> TextureAssetManager::LoadImpl(std::string path)
		{
			auto texture = std::make_shared<graphics::Texture>();
			texture->Load(path.c_str());
			return texture;
		}

		std::shared_ptr<aether::graphics::Font> FontAssetManager::LoadImpl(std::string path)
		{
			auto font = std::make_shared<graphics::Font>();
			font->Load(path.c_str(), 9);
			return font;
		}

	}
}