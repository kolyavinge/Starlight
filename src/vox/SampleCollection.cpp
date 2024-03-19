#include <anx/AudioResources.h>
#include <vox/SampleCollection.h>

void SampleCollection::Init()
{
    SelectMenuItemSample.Load(AudioResources::GetSelectMenuItemWavFilePath());
    CountdownSample.Load(AudioResources::GetCountdownWavFilePath());
    LaserSample.Load(AudioResources::GetLaserWavFilePath());
    MetalHitSample.Load(AudioResources::GetMetalHitWavFilePath());
    ExplosionSample.Load(AudioResources::GetExplosionWavFilePath());
    PowerUpPickSample.Load(AudioResources::GetPowerUpPickWavFilePath());
}
