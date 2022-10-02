#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "../sample.h"
#include "../../core/handledresourcemanager.h"


namespace aether {
namespace audio {


struct AllegroSample
{
    ALLEGRO_SAMPLE* sample;
    ALLEGRO_SAMPLE_ID id;
};

core::HandledResourceManager<AllegroSample> sample_manager;

void Sample::Load(const char *path)
{
    AllegroSample as;
    as.sample = al_load_sample(path);
    SetHandle(sample_manager.createNewHandle(as));
}

void Sample::Destroy()
{
    al_destroy_sample(sample_manager.fetchPresentHandle(GetHandle()).sample);
}

void Sample::Play(float volume, PlayMode playmode)
{
    AllegroSample as = sample_manager.fetchPresentHandle(GetHandle());
    ALLEGRO_PLAYMODE pm = ALLEGRO_PLAYMODE_ONCE;
    if( playmode == PlayMode::Loop )
    {
        pm = ALLEGRO_PLAYMODE_LOOP;
    }
    al_play_sample(as.sample, volume, 0, 1, pm, &as.id);
}

void Sample::Rewind()
{
    AllegroSample as = sample_manager.fetchPresentHandle(GetHandle());
    al_stop_sample(&as.id);
}


}
}
