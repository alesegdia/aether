#pragma once

#include "aether/render/color.h"
#include "aether/core/ModuleObject.h"

namespace aether::render {


    void init_font_system();

    void deinit_font_system();

enum TextAlign
{
	Left,
    Center,
    Right
};

class Font : public core::ModuleObject
{
protected:
    Font(ModuleObject* o) : ModuleObject(o) {}

public:
    // virtual int GetWidthForText(const char* text) = 0;

};


}
