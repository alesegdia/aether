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

void Sample::load(const char *path)
{
    AllegroSample as;
    as.sample = al_load_sample(path);
    handle(sample_manager.setNextHandle(as));
}

void Sample::destroy()
{
    al_destroy_sample(sample_manager.fetch(handle()).sample);
}

void Sample::play(float volume, PlayMode playmode)
{
    AllegroSample as = sample_manager.fetch(handle());
    ALLEGRO_PLAYMODE pm = ALLEGRO_PLAYMODE_ONCE;
    if( playmode == PlayMode::Loop )
    {
        pm = ALLEGRO_PLAYMODE_LOOP;
    }
    al_play_sample(as.sample, volume, 0, 1, pm, &as.id);
}

void Sample::rewind()
{
    AllegroSample as = sample_manager.fetch(handle());
    al_stop_sample(&as.id);
}


}
}
