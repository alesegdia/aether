#pragma once

#include <glm/glm.hpp>

#include "aether/render/Texture.h"

namespace aether::render
{

	class ShaderProgram;
	class Topology;

	class InstancedEntity
	{

	};

	class IBatchedEntity
	{
	public:
		virtual ~IBatchedEntity() = default;

		virtual ShaderProgram* GetShader() const = 0;
		virtual TextureConfig GetTextureConfig() const = 0;
		
		// leave it here just in case we need it later
		// virtual glm::mat4x4 GetEntityModel() = 0;
		
		virtual void Draw() = 0;

		// if it's instanced, it will return the common instanced entity
		// otherwise, it will return nullptr
		virtual InstancedEntity* GetInstancedEntity() const
		{
			return nullptr;
		}

	};

	class IInstancedRenderer
	{
	public:
		virtual ~IInstancedRenderer() = default;

		virtual void RenderInstanced(std::vector<IBatchedEntity*> entitiesToRender) = 0;
	};


}