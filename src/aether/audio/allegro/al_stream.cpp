#include <allegro5/allegro_audio.h>

#include "../stream.h"
#include "../../core/handledresourcemanager.h"


namespace aether {
namespace audio {


struct AllegroStream
{
    ALLEGRO_AUDIO_STREAM* stream;
    ALLEGRO_VOICE* voice;
    double last_pause = 0;
};


core::HandledResourceManager<AllegroStream> stream_manager;


void Stream::load(const char *path)
{
    AllegroStream as;
    as.stream = al_load_audio_stream(path, 4, 2048);
    assert(as.stream);
    as.voice = al_create_voice( 44100, al_get_audio_stream_depth(as.stream),ALLEGRO_CHANNEL_CONF_2 );
    al_attach_audio_stream_to_voice(as.stream, as.voice);
    handle(stream_manager.createNewHandle(as));
    playmode(PlayMode::Loop);
}

void Stream::playmode(PlayMode playmode)
{
    AllegroStream& as = stream_manager.fetchPresentHandleReference(handle());
    ALLEGRO_PLAYMODE pm = ALLEGRO_PLAYMODE_LOOP;

    if( playmode == PlayMode::Once )
    {
        pm = ALLEGRO_PLAYMODE_ONCE;
    }

    al_set_audio_stream_playmode(as.stream, pm);
}

void Stream::play()
{
    AllegroStream as = stream_manager.fetchPresentHandleReference(handle());
    al_set_audio_stream_playing(as.stream, true);
    al_set_voice_playing(as.voice, true);
}

void Stream::pause()
{
    AllegroStream& as = stream_manager.fetchPresentHandleReference(handle());
    al_set_audio_stream_playing(as.stream, false);
    as.last_pause = al_get_audio_stream_position_secs(as.stream);
}

void Stream::resume()
{
    //AllegroStream as = stream_manager.fetch(handle());
    //assert(al_set_audio_stream_loop_secs(as.stream, as.last_pause));
}

bool Stream::playing()
{
    return al_get_audio_stream_playing(stream_manager.fetchPresentHandle(handle()).stream);
}

bool Stream::rewind()
{
    AllegroStream as = stream_manager.fetchPresentHandle(handle());
    al_seek_audio_stream_secs(as.stream, 0);
    return al_rewind_audio_stream(as.stream);
}

void Stream::destroy()
{
    AllegroStream as = stream_manager.fetchPresentHandle(handle());
    al_detach_audio_stream(as.stream);
    al_destroy_audio_stream(as.stream);
    al_destroy_voice(as.voice);
    invalidate();
}


}
}
