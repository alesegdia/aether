#pragma once

#include <nether/nether.h>

#include "aether/scene/SceneNode.h"
#include "aether/render/TextureRegion.h"
#include "aether/core/ModuleObject.h"

namespace aether::render {

    class GLSceneNode : public scene::SceneNode, core::ModuleObject
    {
    public:
        GLSceneNode(ModuleObject* o) : ModuleObject(o) {}

        virtual ~GLSceneNode()
        {

        }

        virtual nether::Texture* GetTexture() = 0;
        virtual nether::Shader* GetShader() = 0;
        virtual nether::Vertices* GetVertices() = 0

    };


}
