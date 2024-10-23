#include "aether/resources/textureassetstorage.h"
#include "aether/core/Engine.h"

namespace aether
{
	namespace resources
	{

		aether::render::Texture* TextureAssetStorage::LoadImpl(std::string path)
		{
			auto texture = aether::GEngine->GetRenderer()->LoadTextureFromFile(path);
			return texture;
		}

	}
}