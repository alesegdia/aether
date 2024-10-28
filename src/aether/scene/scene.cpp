
#include "aether/scene/scene.h"
#include "aether/scene/SceneNode.h"

namespace aether::scene {

    void Scene::Traverse(const std::function<void(SceneNode*)>& functor)
    {
        Traverse(functor, &m_root);
    }

    void Scene::Traverse(const std::function<void(SceneNode*)>& functor, SceneNode* node)
    {
        functor(node);
        for (auto child : node->GetChildren())
        {
            Traverse(functor, child);
        }
    }

    void Scene::Step()
    {
        Traverse([](SceneNode* node) {
            node->ComputeRenderMatrix();
            node->Step();
        }, &m_root);
    }

    void Scene::AddToSceneRoot(SceneNode* node)
    {
        node->SetParent(&m_root);
    }

    void Scene::AddToScene(SceneNode* sceneNode)
    {
        sceneNode->SetParent(&m_root);
    }

    void Scene::SetClearColor(aether::render::Color color)
    {
        m_clearColor = color;
    }

}
