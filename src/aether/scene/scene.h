#pragma once

#include <memory>
#include <vector>

#include "aether/math/vec.h"
#include "aether/render/color.h"
#include "aether/render/render.h"
#include "aether/core/utility.h"


#include "aether/scene/SceneNode.h"

namespace aether::scene {

    class SceneNode;

    class Scene
    {
    public:
        using SharedPtr = std::shared_ptr<Scene>;

        Scene();

        void Render();

        void Traverse(const std::shared_ptr<SceneNode>& node);

        template <typename SceneNodeType, typename... Args>
        std::shared_ptr<SceneNodeType> AddToScene(Args&&... args)
        {
            auto ptr = std::make_shared<SceneNodeType>(args...);
            m_root->AddChild(ptr);
            ptr->SetParent(m_root);
            return ptr;
        }

        void AddToScene(SceneNode* sceneNode);

        void SetClearColor(aether::render::Color color);


    private:
        SceneNode m_root;
        std::vector<std::shared_ptr<SceneNode>> m_nodesSortedByZindex;
        aether::render::Color m_clearColor = aether::render::Color::Black;

    };

}
