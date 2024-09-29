// GLTopology.h
#pragma once

#include <glad/gl.h>
#include "aether/render/Topology.h"
#include "nether/BufferObject.h" // Assuming this is the correct include path for BufferObject

namespace aether::render
{
    /**
     * @brief Class representing an OpenGL topology.
     */
    class GLTopology : public Topology
    {
    public:
        using Topology::Topology; // Inherit constructors from Topology

        /**
         * @brief Configures the vertex attribute pointers for OpenGL based on the vertex format.
         *
         * This method sets up the vertex attribute pointers in OpenGL according to the
         * vertex format defined in the topology. It enables the vertex attribute arrays
         * and specifies the layout of the vertex data, allowing OpenGL to correctly
         * interpret the vertex buffer data during rendering.
         */
        void ConfigureVertexAttribs();

    private:
        nether::BufferObject m_vbo; ///< Vertex Buffer Object
        nether::BufferObject m_ebo; ///< Element Buffer Object
    };
}