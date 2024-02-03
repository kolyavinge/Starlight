#include <anx/AudioResources.h>
#include <vox/SampleCollection.h>

void SampleCollection::Init()
{
    SelectMenuItem.Load(AudioResources::GetSelectMenuItemWavFilePath());
}
