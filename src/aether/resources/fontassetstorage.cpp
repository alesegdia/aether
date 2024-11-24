#include "aether/resources/fontassetstorage.h"
#include "aether/resources/configfile.h"
#include "aether/core/Engine.h"


namespace aether
{
	namespace resources
	{
		aether::render::Font* FontAssetStorage::LoadImpl(std::string path)
		{
			ConfigFile cfg;
			cfg.Load(path.c_str());
			int size = 0;
			std::string fontFile;
			cfg.GetValue("default", "size", size);
			cfg.GetValue("default", "asset", fontFile);
			auto fullPath = GetPath(fontFile);
			auto font = aether::GEngine->CreateFont(fullPath, size);
			return font;
		}

	}
}
