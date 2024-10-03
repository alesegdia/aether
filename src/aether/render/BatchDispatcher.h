#pragma once

#include <vector>
#include "aether/render/Batch.h"

namespace aether::render {

    class IBatchedEntity;
    class Camera;

    struct InstanceBatch
    {
		std::vector<IBatchedEntity*> elements;
    };

    /**
     * @class IBatchActionProvider
     * @brief Interface for batch actions, providing methods for shader preparation, texture preparation, and rendering elements.
     */
    class IBatchActionProvider {
    public:
        virtual ~IBatchActionProvider() = default;

        /**
         * @brief Prepares the shader for the batch.
         * @param batch Reference to the batch.
         */
        virtual void ShaderPreparationStep(Batch& batch) = 0;

        /**
         * @brief Prepares the texture for the batch.
         * @param batch Reference to the batch.
         */
        virtual void TexturePreparationStep(Batch& batch) = 0;

        /**
         * @brief Renders an element in the batch.
         * @param element Reference to the batched entity.
         * @param batch Reference to the batch.
         */
        virtual void RenderElement(const IBatchedEntity& element, Batch& batch) = 0;


        virtual void StartRenderElementsStep() = 0;
        virtual void FinishRenderElementsStep() = 0;

    };

    /**
     * @class BatchDispatcher
     * @brief Manages and dispatches batches of entities for rendering.
     */
    class BatchDispatcher {
    public:
        /**
         * @brief Constructs a BatchDispatcher with the specified batch action provider.
         * @param batchActionProvider Pointer to the batch action provider.
         */
        BatchDispatcher(IBatchActionProvider* batchActionProvider);

        virtual ~BatchDispatcher() = default;

        /**
         * @brief Adds an entity to the appropriate batch.
         * @param node Pointer to the entity to be added.
         */
        void AddToBatch(const IBatchedEntity* node);

        /**
         * @brief Removes an entity from its batch.
         * @param node Pointer to the entity to be removed.
         */
        void RemoveFromBatch(const IBatchedEntity* node);

        /**
         * @brief Renders all batches.
         */
        void Render();

    private:
        /**
         * @brief Adds a new batch for the specified entity.
         * @param node Pointer to the entity.
         * @return Pointer to the created batch.
         */
        Batch* AddBatchForNode(const IBatchedEntity* node);

        /**
         * @brief Gets the best batch for the specified entity.
         * @param node Pointer to the entity.
         * @return Pointer to the best batch.
         */
        Batch* GetBestBatchForNode(const IBatchedEntity* node);

        static constexpr int SameShaderScore = 2; ///< Score for matching shaders.
        static constexpr int SameTextureScore = 1; ///< Score for matching textures.

        std::vector<Batch> m_batches; ///< List of batches.
        IBatchActionProvider* m_batchActionProvider; ///< Pointer to the batch action provider.
    };

}