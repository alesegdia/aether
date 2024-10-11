#pragma once

#include "aether/math/matrix.h"
#include "aether/math/vec.h"
#include "aether/render/spritesheet.h"
#include "aether/render/TextureRegion.h"

#include "aether/core/utility.h"

#include <vector>
#include <functional>

#include <Tmx.h>


class IRenderModule;

namespace aether {
	namespace tilemap {

		class Layer {
		public:
			using Shared = std::shared_ptr<Layer>;

			virtual ~Layer()
			{

			}

			Layer(const std::string& id, int zOrder);

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
