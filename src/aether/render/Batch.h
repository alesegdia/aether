#pragma once

#include <vector>
#include "aether/render/IBatchedEntity.h"
#include "aether/render/ShaderProgram.h"
#include "aether/render/Texture.h"

namespace aether::render {

    /**
     * @class Batch
     * @brief Manages a collection of batched entities that share the same texture and shader.
     */
    class Batch {
    public:
        /**
         * @brief Constructs a Batch with the specified texture and shader.
         * @param texture Pointer to the texture used by the batch.
         * @param shader Pointer to the shader program used by the batch.
         */
        Batch(Texture* texture, ShaderProgram* shader);

        /**
         * @brief Gets the texture used by the batch.
         * @return Pointer to the texture.
         */
        Texture* GetTexture() const;

        /**
         * @brief Gets the shader program used by the batch.
         * @return Pointer to the shader program.
         */
        ShaderProgram* GetShader() const;

        /**
         * @brief Removes an entity from the batch.
         * @param node Pointer to the entity to be removed.
         */
        void RemoveElement(const IBatchedEntity* node);

        /**
         * @brief Adds an entity to the batch.
         * @param node Pointer to the entity to be added.
         */
        void AddElement(const IBatchedEntity* node);

        /**
         * @brief Gets the list of entities in the batch.
         * @return A const reference to the vector of entities.
         */
        const std::vector<const IBatchedEntity*>& GetElements() const;

    private:
        Texture* m_texture; ///< Pointer to the texture used by the batch.
        ShaderProgram* m_shader; ///< Pointer to the shader program used by the batch.
        std::vector<const IBatchedEntity*> m_elements; ///< List of entities in the batch.
    };

}
