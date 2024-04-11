#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <vox/ui/ScreenVox.h>
#include <vox/ui/StartMenuVox.h>
#include <vox/ui/TrackSelectorVox.h>
#include <vox/ui/RacePreparationVox.h>
#include <vox/ui/RaceVox.h>
#include <vox/ui/PauseMenuVox.h>
#include <vox/ui/FinishVox.h>

class VoxManager : public Object
{
    StartMenuVox& _startMenuVox;
    TrackSelectorVox& _trackSelectorVox;
    RacePreparationVox& _racePreparationVox;
    RaceVox& _raceVox;
    PauseMenuVox& _pauseMenuVox;
    FinishVox& _finishVox;
    Array<ScreenVox*, 6> _vox;

public:
    VoxManager(
        StartMenuVox& startMenuVox,
        TrackSelectorVox& trackSelectorVox,
        RacePreparationVox& racePreparationVox,
        RaceVox& raceVox,
        PauseMenuVox& pauseMenuVox,
        FinishVox& finishVox);

    ScreenVox& GetScreenVox(Screen& screen);
};

class VoxManagerResolvingFactory : public ResolvingFactory<VoxManager>
{
public:
    VoxManager* Make(Resolver& resolver) override;
};
