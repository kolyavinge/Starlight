#include <anx/AudioResources.h>
#include <vox/AudioDataCollection.h>

void AudioDataCollection::Init()
{
    SelectMenuItemData.LoadFromFile(AudioResources::GetSelectMenuItemWavFilePath());
    CountdownData.LoadFromFile(AudioResources::GetCountdownWavFilePath());
    LaserData.LoadFromFile(AudioResources::GetLaserWavFilePath());
    MetalHitData.LoadFromFile(AudioResources::GetMetalHitWavFilePath());
    ExplosionData.LoadFromFile(AudioResources::GetExplosionWavFilePath());
    PowerUpPickData.LoadFromFile(AudioResources::GetPowerUpPickWavFilePath());
}

AudioDataCollection* AudioDataCollectionResolvingFactory::Make(Resolver&)
{
    return new AudioDataCollection();
}
