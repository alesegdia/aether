#pragma once

namespace aether::render
{
	class Texture;
	class Font;
	class ShaderProgram;
	class Camera;
	class Sprite;
	class GLTexture;
	class GLFont;
	class GLShaderProgram;
	class GLCamera;
	class GLSpriteNode;
	class GLTilemapNode;
	class GLCamera;
}

namespace aether::scene
{
	class ISpriteNode;
	class ITilemapNode;
}

#define AETHER_MAP_TYPE(T1, T2) \
template<> \
struct OpenGLResourceTraits<T1> \
{ \
	typedef T2 ConcreteType; \
};

template<class T>
struct OpenGLResourceTraits
{
};

AETHER_MAP_TYPE(aether::render::Texture, aether::render::GLTexture)
AETHER_MAP_TYPE(aether::render::Font, aether::render::GLFont)
AETHER_MAP_TYPE(aether::render::ShaderProgram, aether::render::GLShaderProgram)
AETHER_MAP_TYPE(aether::scene::ISpriteNode, aether::render::GLSpriteNode)
AETHER_MAP_TYPE(aether::scene::ITilemapNode, aether::render::GLTilemapNode)
AETHER_MAP_TYPE(aether::render::Camera, aether::render::GLCamera)

template<typename GenericType>
static  typename OpenGLResourceTraits<GenericType>::ConcreteType* ResourceCast(GenericType* Resource)
{
	return static_cast<typename OpenGLResourceTraits<GenericType>::ConcreteType*>(Resource);
}


