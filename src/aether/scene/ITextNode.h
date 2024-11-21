#pragma once

#include "aether/scene/SceneNode.h"
#include "aether/render/Animation.h"
#include "aether/render/AsepriteAnimLoader.h"
#include <unordered_map>
#include <memory>
#include <string>

namespace aether::scene
{
    class ITextNode : public SceneNode
    {
    public:
        ITextNode(core::ModuleObject* o)
			: SceneNode(o)
        {

        }

		virtual void SetText(const std::string& text) = 0;
        virtual void SetSize(int size) = 0;
		virtual void SetColor(const glm::fvec4& color) = 0;
		virtual void SetAlignment(const glm::fvec2& alignment) = 0;
		virtual void SetFont(const std::string& font) = 0;
		virtual void SetLineSpacing(float spacing) = 0;
		virtual void SetClippingRect(float x, float y, float w, float h) = 0;

    private:

    };
}