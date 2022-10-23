#include "aether/resources/textureassetstorage.h"

namespace aether
{
	namespace resources
	{

		std::shared_ptr<aether::graphics::Texture> TextureAssetStorage::LoadImpl(std::string path)
		{
			auto texture = std::make_shared<graphics::Texture>();
			texture->Load(path.c_str());
			return texture;
		}

	}
}