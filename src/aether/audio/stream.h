#pragma once

#include "../core/handle.h"
#include "audio.h"

namespace aether {
namespace audio {

class Stream : public core::Handle
{
public:

    Stream() {}

    void load(const char* path);
    void playmode(PlayMode playmode);
    void play();
    void pause();
    void resume();
    bool playing();
    bool rewind();
    void destroy();

};

}
}
