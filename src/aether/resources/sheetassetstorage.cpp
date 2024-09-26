#include "aether/resources/sheetassetstorage.h"

#include "configfile.h"
#include "inipp/inipp.h"

#include "aether/render/IRenderModule.h"

namespace aether
{
	namespace resources
	{

		std::shared_ptr<aether::render::Spritesheet> SheetAssetStorage::LoadImpl(std::string path)
		{
			auto spritesheet = std::make_shared<render::Spritesheet>();

			ConfigFile configFile;
			configFile.Load(path.c_str());

			int rows, cols;
			std::string relPath;
			configFile.GetValue("default", "rows", rows);
			configFile.GetValue("default", "cols", cols);
			configFile.GetValue("default", "asset", relPath);

			auto texture = m_renderModule->LoadTextureFromFile(path);
			m_cachedTextures.push_back(texture);

			spritesheet->Load(cols, rows, texture);
			return spritesheet;		
		}

	}
}