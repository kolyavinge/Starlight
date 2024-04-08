#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <vox/AudioDataCollection.h>
#include <vox/ScreenVox.h>
#include <vox/StartMenuVox.h>
#include <vox/TrackSelectorVox.h>
#include <vox/RacePreparationVox.h>
#include <vox/RaceVox.h>
#include <vox/PauseMenuVox.h>
#include <vox/FinishVox.h>

class ScreenVoxCollection : public Object
{
    AudioDataCollection& _audioDataCollection;
    StartMenuVox& _startMenuVox;
    TrackSelectorVox& _trackSelectorVox;
    RacePreparationVox& _racePreparationVox;
    RaceVox& _raceVox;
    PauseMenuVox& _pauseMenuVox;
    FinishVox& _finishVox;
    Array<ScreenVox*, 6> _vox;

public:
    ScreenVoxCollection(
        AudioDataCollection& audioDataCollection,
        StartMenuVox& startMenuVox,
        TrackSelectorVox& trackSelectorVox,
        RacePreparationVox& racePreparationVox,
        RaceVox& raceVox,
        PauseMenuVox& pauseMenuVox,
        FinishVox& finishVox);

    void Init();
    ScreenVox& GetScreenVox(Screen& screen);
};

class ScreenVoxCollectionResolvingFactory : public ResolvingFactory<ScreenVoxCollection>
{
public:
    ScreenVoxCollection* Make(Resolver& resolver) override;
};
