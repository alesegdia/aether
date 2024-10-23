#include "aether/resources/fontassetstorage.h"
#include "aether/resources/configfile.h"


/*
namespace aether
{
	namespace resources
	{
		std::shared_ptr<aether::graphics::Font> FontAssetStorage::LoadImpl(std::string path)
		{
			auto font = std::make_shared<graphics::Font>();
			ConfigFile cfg;
			cfg.Load(path.c_str());
			int size = 0;
			std::string fontFile;
			cfg.GetValue("default", "size", size);
			cfg.GetValue("default", "asset", fontFile);
			auto fullPath = GetPath(fontFile);
			font->Load(fullPath.c_str(), size);
			return font;
		}

	}
}
*/