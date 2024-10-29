#include "aether/render/gl/GLRenderModule.h"
#include "nether/nether.h"
#include "aether/render/gl/GLShaderProgram.h"

#include "aether/render/Camera.h"

#include <glm/glm.hpp>
#include "aether/render/gl/GLResources.h"

#include "aether/render/BatchDispatcher.h"

namespace aether {

	aether::render::IRenderModule* create_render_module()
	{
		return new aether::render::GLRenderModule();
	}

}

namespace aether::render {

    GLRenderModule::GLRenderModule()
        : IRenderModule(this)
        , m_batchDispatcher(this)
    {
    }

    void GLRenderModule::Init()
    {
        m_defaultShader = new GLShaderProgram(this, "media/default.vs", "media/default.fs");
        m_spriteShader = new GLShaderProgram(this, "media/sprite.vs", "media/sprite.fs");
        
        m_defaultShader->Use();
        m_defaultShader->SetIntUniform("texture1", 0);
        
        m_spriteShader->Use();
        m_spriteShader->SetIntUniform("texture1", 0);
    }

    GLRenderModule::~GLRenderModule()
    {
        m_allFonts.clear();
        m_allTextures.clear();
        m_allCameras.clear();
        m_allSprites.clear();
		if (m_tilemapShader != nullptr)
		{
			delete m_tilemapShader;
		}
        if (m_spriteShader!= nullptr)
		{
			delete m_tilemapShader;
		}
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

    Camera* GLRenderModule::CreateCamera(const glm::fvec2& viewport, ProjectionMode projectionMode)
    {
        m_allCameras.emplace_back(new Camera(this, viewport, projectionMode));
        return m_allCameras.back();
    }

    Sprite* GLRenderModule::CreateSprite(Texture* texture, const math::Recti& rect)
    {
        m_allSprites.emplace_back(new Sprite(this, texture));
        m_allSprites.back()->SetClippingRect(rect.x(), rect.y(), rect.w(), rect.h());
        return m_allSprites.back();
    }

    void GLRenderModule::Render()
    {
        auto clearColor = GetClearColor();
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_batchDispatcher.Render();
    }

    scene::ISpriteNode* GLRenderModule::CreateSpriteNode(const glm::fvec2& size)
    {
		auto node = new GLSpriteNode(this, m_spriteShader, size);
        m_allSpriteNodes.emplace_back(node);
        m_batchDispatcher.AddToBatch(node);
        return node;
    }

    scene::ITilemapNode* GLRenderModule::CreateTilemapNode(const aether::tilemap::TileMap& map)
    {
		auto node = new GLTilemapNode(this, m_tilemapShader, nullptr);
		m_allTilemapNodes.emplace_back(node);
        m_batchDispatcher.AddToBatch(node);
        return node;
    }

    void GLRenderModule::RenderElement(IBatchedEntity& element, Batch& batch)
    {
		element.Draw();
    }

    void GLRenderModule::ShaderPreparationStep(IBatchedEntity* batch)
    {
		auto shader = ResourceCast(batch->GetShader());
        shader->GetNetherShader()->Use();
        shader->GetNetherShader()->SetMat4Uniform("viewProjection", GetActiveCamera()->GetViewProjectionMatrix());
    }

    void GLRenderModule::TexturePreparationStep(IBatchedEntity* batch)
    {
        auto entries = batch->GetTextureConfig().GetEntries();
        for (auto entry : entries)
		{
			auto texture = ResourceCast(entry.GetTexture());

			// fixme: this is a hack, we need to bind the texture to the correct texture unit
			texture->GetNetherTexture()->Bind(nether::TextureUnit::Texture0);
        }
    }

    void GLRenderModule::StartRenderElementsStep()
    {
        // Implementation for starting the render elements step
    }

    void GLRenderModule::FinishRenderElementsStep()
    {
        // Implementation for finishing the render elements step
    }

	void GLRenderModule::RenderInstanced(InstancedEntity* entity, InstanceBatch* batch)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

} // namespace aether::render

