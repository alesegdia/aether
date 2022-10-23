#include "aether/resources/sheetassetstorage.h"

#include "configfile.h"
#include "inipp/inipp.h"

namespace aether
{
	namespace resources
	{

		std::shared_ptr<aether::graphics::Spritesheet> TextureAssetStorage::LoadImpl(std::string path)
		{
			/*
			auto spritesheet = std::make_shared<graphics::Spritesheet>();
			auto texture = std::make_shared<graphics::Texture>();

			ConfigFile configFile;
			configFile.Load(path.c_str());



			texture->Load(path);
			spritesheet->Load(10, 10, m_cachedTextures[0]);
			return spritesheet;
			*/
			return nullptr;
		}

	}
}