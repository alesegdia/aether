#pragma once

#include "../core/handle.h"
#include "playmode.h"

namespace aether {
namespace audio {

/// <summary>
/// The stream class handles an audio source intended to be streamed like a game theme.
/// Support is only available for MP3 and WAV.
/// </summary>
class Stream : public core::Handle
{
public:

    Stream() {}

    /// <summary>
    /// Loads the selected audio stream file
    /// </summary>
    /// <param name="path"></param>
    void Load(const char* path);

    /// <summary>
    /// Sets the play mode to be 
    /// </summary>
    /// <param name="playmode"></param>
    void SetPlayMode(PlayMode playmode);

    /// <summary>
    /// Plays the audio stream
    /// </summary>
    void Play();

    /// <summary>
    /// Pauses the audio stream
    /// </summary>
    void Pause();

    /// <summary>
    /// Resumes the audio stream, previously paused
    /// </summary>
    void Resume();

    /// <summary>
    /// Checks whether the audio stream is currently playing or not
    /// </summary>
    /// <returns></returns>
    bool Playing();

    /// <summary>
    /// Returns the audio stream peek to the beginning
    /// </summary>
    /// <returns></returns>
    bool Rewind();

    /// <summary>
    /// Destroys the audio stream and can't be used anymore
    /// The object gets invalidated
    /// </summary>
    void Destroy();

};

}
}
