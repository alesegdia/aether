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

			// Extract base directory from path
			std::filesystem::path basePath = std::filesystem::path(path).parent_path();
			std::filesystem::path fullPath = basePath / fontFile;

			auto font = aether::GEngine->CreateFont(fullPath.generic_string(), size);

			return font;
		}

	}
}
