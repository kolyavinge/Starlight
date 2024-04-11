#include <anx/AudioResources.h>
#include <vox/AudioDataCollection.h>

AudioDataCollection::AudioDataCollection()
{
    SelectMenuItemData.LoadFromFile(AudioResources::GetSelectMenuItemWavFilePath());
    CountdownData.LoadFromFile(AudioResources::GetCountdownWavFilePath());
    LaserData.LoadFromFile(AudioResources::GetLaserWavFilePath());
    MetalHitData.LoadFromFile(AudioResources::GetMetalHitWavFilePath());
    ExplosionData.LoadFromFile(AudioResources::GetExplosionWavFilePath());
    PowerUpPickData.LoadFromFile(AudioResources::GetPowerUpPickWavFilePath());
    EngineIdleData.LoadFromFile(AudioResources::GetEngineIdleWavFilePath());
    EngineThrottleData.LoadFromFile(AudioResources::GetEngineThrottleWavFilePath());
}

AudioDataCollection* AudioDataCollectionResolvingFactory::Make(Resolver&)
{
    return new AudioDataCollection();
}
