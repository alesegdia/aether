#pragma once

#include <string>
#include <memory>

namespace aether {
    namespace tilemap {

        class Layer {
        public:
            using Shared = std::shared_ptr<Layer>;

            Layer(const std::string& id, int zOrder);

            virtual ~Layer();
            virtual void Render() = 0;

            const std::string& GetName();

            int GetDepthOrder() const;

            void SetVisible(bool visible)
            {
                m_visible = visible;
            }

            bool IsVisible()
            {
                return m_visible;
            }

        private:
            std::string m_name;
            int m_depthOrder = 0;
            bool m_visible = true;
        };

    }
}