#include <vox/ui/VoxManager.h>

VoxManager::VoxManager(
    StartMenuVox& startMenuVox,
    TrackSelectorVox& trackSelectorVox,
    RacePreparationVox& racePreparationVox,
    RaceVox& raceVox,
    PauseMenuVox& pauseMenuVox,
    FinishVox& finishVox) :
    _startMenuVox(startMenuVox),
    _trackSelectorVox(trackSelectorVox),
    _racePreparationVox(racePreparationVox),
    _raceVox(raceVox),
    _pauseMenuVox(pauseMenuVox),
    _finishVox(finishVox)
{
    _vox[(int)ScreenKind::StartMenu] = &_startMenuVox;
    _vox[(int)ScreenKind::TrackSelector] = &_trackSelectorVox;
    _vox[(int)ScreenKind::RacePreparation] = &_racePreparationVox;
    _vox[(int)ScreenKind::Race] = &_raceVox;
    _vox[(int)ScreenKind::PauseMenu] = &_pauseMenuVox;
    _vox[(int)ScreenKind::Finish] = &_finishVox;
}

ScreenVox& VoxManager::GetScreenVox(Screen& screen)
{
    return *_vox[(int)screen.Kind];
}

VoxManager* VoxManagerResolvingFactory::Make(Resolver& resolver)
{
    return new VoxManager(
        resolver.Resolve<StartMenuVox>(),
        resolver.Resolve<TrackSelectorVox>(),
        resolver.Resolve<RacePreparationVox>(),
        resolver.Resolve<RaceVox>(),
        resolver.Resolve<PauseMenuVox>(),
        resolver.Resolve<FinishVox>());
}
