#pragma once

#include "../core/handle.h"
#include "playmode.h"

namespace aether {
namespace audio {


class Sample : public core::Handle
{
public:
    Sample() {}

    void load(const char* path);
    void destroy();
    void play(float volume=1.f, PlayMode playmode = PlayMode::Once);
    void rewind();

};


}
}
