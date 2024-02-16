#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <ui/Screen.h>
#include <vox/SampleCollection.h>
#include <vox/ScreenVox.h>
#include <vox/StartMenuVox.h>
#include <vox/TrackSelectorVox.h>
#include <vox/RacePreparationVox.h>
#include <vox/RaceVox.h>
#include <vox/PauseMenuVox.h>
#include <vox/FinishVox.h>

class ScreenVoxCollection : public Object
{
    SampleCollection _sampleCollection;
    StartMenuVox _startMenuVox;
    TrackSelectorVox _trackSelectorVox;
    RacePreparationVox _racePreparationVox;
    RaceVox _raceVox;
    PauseMenuVox _pauseMenuVox;
    FinishVox _finishVox;
    Array<ScreenVox*, 6> _vox;

public:
    ScreenVoxCollection();

    void Init();
    ScreenVox& GetScreenVox(Screen& screen);
};
