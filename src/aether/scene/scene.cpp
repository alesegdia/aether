
#include "aether/scene/scene.h"
#include "aether/scene/SceneNode.h"

namespace aether::scene {

    Scene::Scene()
    {
        m_root = std::make_shared<SceneNode>();
        m_root->SetParent(std::make_shared<SceneNode>());
    }

    void Scene::Render()
    {
        aether::graphics::clear(m_clearColor);
        m_nodesSortedByZindex.clear();
        Traverse(m_root);
        for (auto child : m_nodesSortedByZindex) {
            child->Render();
        }
    }

    void Scene::Traverse(const std::shared_ptr<SceneNode>& node)
    {
        core::insert_sorted(m_nodesSortedByZindex, node, [](auto val, auto iter) {
            return val->GetZIndex() < iter->GetZIndex();
            });
        auto parent = node->GetParent();
        auto newRenderPosition = (parent == nullptr ? node->GetRelativePosition() : parent->GetRelativePosition() + node->GetRelativePosition());
        node->SetRenderPosition(newRenderPosition);
        for (auto child : node->GetChildren()) {
            Traverse(child);
        }
    }

    void Scene::AddToScene(std::shared_ptr<SceneNode> sceneNode)
    {
        m_root->AddChild(sceneNode);
        sceneNode->SetParent(m_root);
    }

    void Scene::SetClearColor(aether::graphics::Color color)
    {
        m_clearColor = color;
    }

}
