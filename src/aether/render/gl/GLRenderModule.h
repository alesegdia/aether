#pragma once

#include "aether/render/IRenderModule.h"
#include "aether/render/BatchDispatcher.h"
#include "aether/render/gl/GLCamera.h"
#include "aether/render/gl/GLFont.h"
#include "aether/render/gl/GLTexture.h"
#include "aether/scene/spritenode.h"
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

        Texture* LoadTextureFromFile(const std::string& path) override;
        Font* LoadFontFromFile(const std::string& path, int size) override;
        ShaderProgram* LoadShaderFromFile(const std::string& vspath, const std::string& fspath) override;
        Camera* CreateCamera(const math::Vec2<float>& position, float rotation) override;
        Sprite* CreateSprite(Texture* texture, const math::Recti& rect) override;
        void Render();
        scene::ISpriteNode* CreateSpriteNode() override;
        scene::ITilemapNode* CreateTilemapNode() override;

        void RenderElement(const IBatchedEntity& element, Batch& batch) override;
        void ShaderPreparationStep(Batch& batch) override;
        void TexturePreparationStep(Batch& batch) override;
        void StartRenderElementsStep() override;
        void FinishRenderElementsStep() override;

    private:
        BatchDispatcher m_batchDispatcher;
        std::vector<GLFont> m_allFonts;
        std::vector<GLTexture> m_allTextures;
        std::vector<GLCamera> m_allCameras;
        std::vector<Sprite> m_allSprites;
    };

} // namespace aether::render

