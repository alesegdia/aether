#pragma once

namespace aether::render
{

	class ShaderProgram;
	class Texture;
	class Topology;

	class IBatchedEntity
	{
	public:
		virtual ~IBatchedEntity() = default;

		virtual ShaderProgram* GetShader() const = 0;
		virtual Texture* GetTexture() const = 0;
		virtual Topology* GetTopology() const = 0;
	};

}