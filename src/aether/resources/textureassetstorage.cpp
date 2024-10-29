#include "aether/resources/textureassetstorage.h"
#include "aether/render/IRenderModule.h"
#include "aether/core/Engine.h"

namespace aether
{
	namespace resources
	{

		aether::render::Texture* TextureAssetStorage::LoadImpl(std::string path)
		{
			auto texture = aether::GEngine->GetRenderModuleAccessor()->LoadTextureFromFile(path);
			return texture;
		}

	}
}