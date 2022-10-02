#pragma once

#include "../core/handle.h"
#include "playmode.h"

namespace aether {
namespace audio {


class Sample : public core::Handle
{
public:
    Sample() {}

    void Load(const char* path);
    void Destroy();
    void Play(float volume=1.f, PlayMode playmode = PlayMode::Once);
    void Rewind();

};


}
}
