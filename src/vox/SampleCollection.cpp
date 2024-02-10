#include <anx/AudioResources.h>
#include <vox/SampleCollection.h>

void SampleCollection::Init()
{
    SelectMenuItemSample.Load(AudioResources::GetSelectMenuItemWavFilePath());
    CountdownSample.Load(AudioResources::GetCountdownWavFilePath());
}
