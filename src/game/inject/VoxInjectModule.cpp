#include <vox/FinishVox.h>
#include <vox/PauseMenuVox.h>
#include <vox/RacePreparationVox.h>
#include <vox/RaceVox.h>
#include <vox/AudioDataCollection.h>
#include <vox/ScreenVoxCollection.h>
#include <vox/StartMenuVox.h>
#include <vox/TrackSelectorVox.h>
#include <vox/VoxManager.h>
#include <game/inject/VoxInjectModule.h>

void VoxInjectModule::Init(Binder& binder)
{
    binder.BindSingletonByFactory<FinishVox, FinishVoxResolvingFactory>();
    binder.BindSingletonByFactory<PauseMenuVox, PauseMenuVoxResolvingFactory>();
    binder.BindSingletonByFactory<RacePreparationVox, RacePreparationVoxResolvingFactory>();
    binder.BindSingletonByFactory<RaceVox, RaceVoxResolvingFactory>();
    binder.BindSingletonByFactory<AudioDataCollection, AudioDataCollectionResolvingFactory>();
    binder.BindSingletonByFactory<ScreenVoxCollection, ScreenVoxCollectionResolvingFactory>();
    binder.BindSingletonByFactory<StartMenuVox, StartMenuVoxResolvingFactory>();
    binder.BindSingletonByFactory<TrackSelectorVox, TrackSelectorVoxResolvingFactory>();
    binder.BindSingletonByFactory<VoxManager, VoxManagerResolvingFactory>();
}
