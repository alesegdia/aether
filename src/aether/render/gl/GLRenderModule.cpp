#include "aether/render/gl/GLRenderModule.h"
#include "nether/nether.h"
#include "aether/render/gl/GLShaderProgram.h"


#include "aether/render/gl/GLResources.h"

namespace aether::render {

    GLRenderModule::GLRenderModule()
        : IRenderModule(this)
        , m_batchDispatcher(this)
    {

    }

    GLRenderModule::~GLRenderModule()
    {
        m_allFonts.clear();
        m_allTextures.clear();
        m_allCameras.clear();
        m_allSprites.clear();
    }

    Texture* GLRenderModule::LoadTextureFromFile(const std::string& path)
    {
        std::shared_ptr<nether::Texture> netherTex = std::make_shared<nether::Texture>();
        netherTex->LoadFromFile(path, nether::TextureFormat::RGBA8);
        m_allTextures.emplace_back(this, netherTex);
        return &m_allTextures.back();
    }

    Font* GLRenderModule::LoadFontFromFile(const std::string& path, int size)
    {
        m_allFonts.emplace_back(this, path, size);
        return &m_allFonts.back();
    }

    ShaderProgram* GLRenderModule::LoadShaderFromFile(const std::string& vspath, const std::string& fspath)
    {
        auto shaderProgram = new GLShaderProgram(this, vspath, fspath);
        return shaderProgram;
    }

    Camera* GLRenderModule::CreateCamera(const math::Vec2<float>& position, float rotation)
    {
        m_allCameras.emplace_back(this, position, rotation);
        return &m_allCameras.back();
    }

    Sprite* GLRenderModule::CreateSprite(Texture* texture, const math::Recti& rect)
    {
        m_allSprites.emplace_back(new Sprite(this, texture));
        m_allSprites.back()->SetClippingRect(rect.x(), rect.y(), rect.w(), rect.h());
        return m_allSprites.back();
    }

    void GLRenderModule::Render()
    {
        m_batchDispatcher.Render();
    }

    scene::ISpriteNode* GLRenderModule::CreateSpriteNode()
    {
        m_allSpriteNodes.emplace_back(this);
        return &m_allSpriteNodes.back();
    }

    scene::ITilemapNode* GLRenderModule::CreateTilemapNode()
    {
        m_allTilemapNodes.emplace_back(new GLTilemapNode(this));
        return m_allTilemapNodes.back();
    }

    void GLRenderModule::RenderElement(const IBatchedEntity& element, Batch& batch)
    {
		element.Render(batch);
    }

    void GLRenderModule::ShaderPreparationStep(Batch& batch)
    {
		auto shader = ResourceCast(batch.GetShader());
        shader->GetNetherShader()->Use();
    }

    void GLRenderModule::TexturePreparationStep(Batch& batch)
    {
        auto texture = ResourceCast(batch.GetTexture());
        texture->GetNetherTexture()->Bind(nether::TextureUnit::Texture0);
    }

    void GLRenderModule::StartRenderElementsStep()
    {
        // Implementation for starting the render elements step
    }

    void GLRenderModule::FinishRenderElementsStep()
    {
        // Implementation for finishing the render elements step
    }

    aether::render::IRenderModule* create_render_module()
    {
        return new aether::render::GLRenderModule();
    }
} // namespace aether::render

