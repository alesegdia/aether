#pragma once

#include "aether/render/IRenderModule.h"
#include "aether/render/BatchDispatcher.h"
#include "aether/render/gl/GLFont.h"
#include "aether/render/gl/GLTexture.h"
#include "aether/render/gl/GLShaderProgram.h"
#include "aether/render/gl/GLSpriteNode.h"
#include "aether/render/gl/GLTilemap.h"
#include "aether/render/Sprite.h"
#include "aether/scene/SceneNodeFactory.h"
#include <nether/nether.h>
#include <vector>
#include <string>

namespace aether::scene
{
    class ISpriteNode;
    class ITilemapNode;
}

namespace aether::render {

    /**
     * @brief OpenGL implementation of the render module.
     */
    class GLRenderModule : public IRenderModule, public IBatchActionProvider
    {
    public:
        GLRenderModule();
        ~GLRenderModule();

        void Render() override;

        Texture* LoadTextureFromFile(const std::string& path) override;
        Font* LoadFontFromFile(const std::string& path, int size) override;
        ShaderProgram* LoadShaderFromFile(const std::string& vspath, const std::string& fspath) override;
        Sprite* CreateSprite(Texture* texture, const math::Recti& rect) override;
        scene::ISpriteNode* CreateSpriteNode(const glm::fvec2& size) override;
        scene::ITilemapNode* CreateTilemapNode() override;

        void RenderElement(IBatchedEntity& element, Batch& batch) override;
        void ShaderPreparationStep(IBatchedEntity* batch) override;
        void TexturePreparationStep(IBatchedEntity* batch) override;
        void StartRenderElementsStep() override;
        void FinishRenderElementsStep() override;
        void Init() override;

        Camera* CreateCamera(const glm::fvec2& viewport, ProjectionMode projectionMode) override;

        void RenderInstanced(InstancedEntity* entity, InstanceBatch* batch) override;

        void Refresh(IBatchedEntity* entity) override
        {
            m_batchDispatcher.Refresh(entity);
        }

    private:
        BatchDispatcher m_batchDispatcher;
        std::vector<GLFont> m_allFonts;
        std::vector<GLTexture> m_allTextures;
        std::vector<Camera*> m_allCameras;
        std::vector<GLShaderProgram> m_allShaders;
		std::vector<Sprite*> m_allSprites;

        // Scene Nodes
		std::vector<render::GLSpriteNode*> m_allSpriteNodes;
		std::vector<render::GLTilemapNode*> m_allTilemapNodes;

        // Active nodes
        std::vector<IBatchedEntity*> m_activeBatchedEntities;

        // Shaders
        GLShaderProgram* m_defaultShader = nullptr;
        GLShaderProgram* m_spriteShader = nullptr;
        GLShaderProgram* m_tilemapShader = nullptr;

        /*
		template<typename NodeType, typename... Args>
		NodeType* CreateNode(std::vector<NodeType*>& v, Args&&... args)
		{
			auto node = new NodeType(this, std::forward<Args>(args)...);
			v.emplace_back(node);
			m_activeBatchedEntities.push_back(node);
			return node;
		}
        */

        template <typename T>
        void RemoveElementFromVector(std::vector<T*>& v, T* obj)
        {
            auto it = std::find(v.begin(), v.end(), obj);
            if (it != v.end())
            {
				delete* it;
                v.erase(it);
            }
        }


    };

} // namespace aether::render