#pragma once

#include <memory>
#include <vector>
#include <functional>

#include "aether/math/vec.h"
#include "aether/render/color.h"
#include "aether/render/render.h"
#include "aether/core/utility.h"


#include "aether/scene/SceneNode.h"
#include "aether/core/ModuleObject.h"

namespace aether::scene {

    class SceneNode;
    class ISceneNodeFactory;

    class Scene : public core::ModuleObject
    {
    public:
        using SharedPtr = std::shared_ptr<Scene>;

        Scene()
			: core::ModuleObject(this)
            , m_root(this)
        {
        }

        void Traverse(const std::function<void(SceneNode*)>& functor);

        void AddToSceneRoot(SceneNode* node);

        void AddToScene(SceneNode* sceneNode);

        void SetClearColor(aether::render::Color color);

        void Step();

    private:
        void Traverse(const std::function<void(SceneNode*)>& functor, SceneNode* node);

        SceneNode m_root;
        std::vector<std::shared_ptr<SceneNode>> m_nodesSortedByZindex;
        aether::render::Color m_clearColor = aether::render::Color::Black;

    };

}
