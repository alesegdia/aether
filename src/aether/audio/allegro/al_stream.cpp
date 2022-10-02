#include <allegro5/allegro_audio.h>

#include "../stream.h"
#include "../../core/handledresourcemanager.h"


namespace aether {
namespace audio {


struct AllegroStream
{
    ALLEGRO_AUDIO_STREAM* stream{};
    ALLEGRO_VOICE* voice{};
    double last_pause = 0;
};


core::HandledResourceManager<AllegroStream> stream_manager;


void Stream::Load(const char *path)
{
    AllegroStream as;
    as.stream = al_load_audio_stream(path, 4, 2048);
    assert(as.stream);
    as.voice = al_create_voice( 44100, al_get_audio_stream_depth(as.stream),ALLEGRO_CHANNEL_CONF_2 );
    al_attach_audio_stream_to_voice(as.stream, as.voice);
    SetHandle(stream_manager.createNewHandle(as));
    SetPlayMode(PlayMode::Loop);
}

void Stream::SetPlayMode(PlayMode playmode)
{
    AllegroStream& as = stream_manager.fetchPresentHandleReference(GetHandle());
    ALLEGRO_PLAYMODE pm = ALLEGRO_PLAYMODE_LOOP;

    if( playmode == PlayMode::Once )
    {
        pm = ALLEGRO_PLAYMODE_ONCE;
    }

    al_set_audio_stream_playmode(as.stream, pm);
}

void Stream::Play()
{
    AllegroStream as = stream_manager.fetchPresentHandleReference(GetHandle());
    al_set_audio_stream_playing(as.stream, true);
    al_set_voice_playing(as.voice, true);
}

void Stream::Pause()
{
    AllegroStream& as = stream_manager.fetchPresentHandleReference(GetHandle());
    al_set_audio_stream_playing(as.stream, false);
    as.last_pause = al_get_audio_stream_position_secs(as.stream);
}

void Stream::Resume()
{
    //AllegroStream as = stream_manager.fetch(handle());
    //assert(al_set_audio_stream_loop_secs(as.stream, as.last_pause));
}

bool Stream::Playing()
{
    return al_get_audio_stream_playing(stream_manager.fetchPresentHandle(GetHandle()).stream);
}

bool Stream::Rewind()
{
    AllegroStream as = stream_manager.fetchPresentHandle(GetHandle());
    al_seek_audio_stream_secs(as.stream, 0);
    return al_rewind_audio_stream(as.stream);
}

void Stream::Destroy()
{
    AllegroStream as = stream_manager.fetchPresentHandle(GetHandle());
    al_detach_audio_stream(as.stream);
    al_destroy_audio_stream(as.stream);
    al_destroy_voice(as.voice);
    Invalidate();
}


}
}
