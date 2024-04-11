#include <vox/ui/FinishVox.h>
#include <vox/ui/PauseMenuVox.h>
#include <vox/ui/RacePreparationVox.h>
#include <vox/ui/RaceVox.h>
#include <vox/ui/StartMenuVox.h>
#include <vox/ui/TrackSelectorVox.h>
#include <vox/ui/VoxManager.h>
#include <vox/common/AudioDataCollection.h>
#include <vox/common/ShipVox.h>
#include <game/inject/VoxInjectModule.h>

void VoxInjectModule::Init(Binder& binder)
{
    binder.BindSingletonByFactory<FinishVox, FinishVoxResolvingFactory>();
    binder.BindSingletonByFactory<PauseMenuVox, PauseMenuVoxResolvingFactory>();
    binder.BindSingletonByFactory<RacePreparationVox, RacePreparationVoxResolvingFactory>();
    binder.BindSingletonByFactory<RaceVox, RaceVoxResolvingFactory>();
    binder.BindSingletonByFactory<StartMenuVox, StartMenuVoxResolvingFactory>();
    binder.BindSingletonByFactory<TrackSelectorVox, TrackSelectorVoxResolvingFactory>();
    binder.BindSingletonByFactory<VoxManager, VoxManagerResolvingFactory>();
    binder.BindSingletonByFactory<AudioDataCollection, AudioDataCollectionResolvingFactory>();
    binder.BindSingletonByFactory<ShipVox, ShipVoxResolvingFactory>();
}
