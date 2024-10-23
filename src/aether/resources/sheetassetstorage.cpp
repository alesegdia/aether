#include "aether/resources/sheetassetstorage.h"

#include "configfile.h"
#include "inipp/inipp.h"

#include "aether/render/IRenderModule.h"

#include "aether/core/Engine.h"

namespace aether
{
	namespace resources
	{

		aether::render::Spritesheet* SheetAssetStorage::LoadImpl(std::string path)
		{
			auto spritesheet = new render::Spritesheet();

			ConfigFile configFile;
			configFile.Load(path.c_str());

			int rows, cols;
			std::string relPath;
			configFile.GetValue("default", "rows", rows);
			configFile.GetValue("default", "cols", cols);
			configFile.GetValue("default", "asset", relPath);

			auto texture = aether::GEngine->GetRenderer()->LoadTextureFromFile(path);
			m_cachedTextures.push_back(texture);
			m_cachedSheets.push_back(spritesheet);

			spritesheet->Load(cols, rows, texture);
			return spritesheet;		
		}

	}
}