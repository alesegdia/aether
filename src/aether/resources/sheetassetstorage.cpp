#include "aether/resources/sheetassetstorage.h"

#include "configfile.h"
#include "inipp/inipp.h"

namespace aether
{
	namespace resources
	{

		std::shared_ptr<aether::graphics::Spritesheet> SheetAssetStorage::LoadImpl(std::string path)
		{
			auto spritesheet = std::make_shared<graphics::Spritesheet>();
			auto texture = std::make_shared<graphics::Texture>();

			ConfigFile configFile;
			configFile.Load(path.c_str());

			int rows, cols;
			std::string relPath;
			configFile.GetValue("default", "rows", rows);
			configFile.GetValue("default", "cols", cols);
			configFile.GetValue("default", "asset", relPath);

			texture->Load(GetPath(relPath).c_str());
			m_cachedTextures.push_back(texture);

			spritesheet->Load(cols, rows, *texture);
			return spritesheet;		
		}

	}
}