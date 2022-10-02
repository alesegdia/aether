#pragma once

#include "../core/handle.h"
#include "playmode.h"

namespace aether {
namespace audio {

class Stream : public core::Handle
{
public:

    Stream() {}

    void Load(const char* path);
    void SetPlayMode(PlayMode playmode);
    void Play();
    void Pause();
    void Resume();
    bool Playing();
    bool Rewind();
    void Destroy();

};

}
}
