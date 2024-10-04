#pragma once

#include <glm/glm.hpp>

namespace aether::render
{

	class ShaderProgram;
	class Texture;
	class Topology;

	class InstancedEntity
	{

	};

	class IBatchedEntity
	{
	public:
		virtual ~IBatchedEntity() = default;

		virtual ShaderProgram* GetShader() const = 0;
		virtual Texture* GetTexture() const = 0;
		virtual glm::mat4x4 GetEntityModel() = 0;
		
		virtual void Draw() const = 0;

		virtual bool IsInstanced() const = 0;

		// if it's instanced, it will return the common instanced entity
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