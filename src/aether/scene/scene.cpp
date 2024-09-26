
#include "aether/scene/scene.h"
#include "aether/scene/SceneNode.h"

namespace aether::scene {

    Scene::Scene()
        : ModuleObject(nullptr)
        , m_root(this)
    {

    }

    void Scene::Traverse(const std::function<void(SceneNode*)>& functor)
    {
        Traverse(functor, &m_root);
    }

    void Scene::Traverse(const std::function<void(SceneNode*)>& functor, SceneNode* node)
    {
        functor(&m_root);
        for (auto child : node->GetChildren())
        {
            Traverse(functor, child);
        }
    }

    void Scene::Step()
    {
        Traverse([](SceneNode* node) {
            node->ComputeRenderMatrix();
        }, &m_root);
    }

    void Scene::AddToScene(SceneNode* sceneNode)
    {
        m_root.AddChild(sceneNode);
        sceneNode->SetParent(&m_root);
    }

    void Scene::SetClearColor(aether::render::Color color)
    {
        m_clearColor = color;
    }

}
