#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <ui/Screen.h>
#include <vox/SampleCollection.h>
#include <vox/ScreenVox.h>
#include <vox/StartMenuVox.h>
#include <vox/TrackSelectorVox.h>
#include <vox/RaceVox.h>
#include <vox/PauseMenuVox.h>

class ScreenVoxCollection : public Object
{
    SampleCollection _sampleCollection;
    StartMenuVox _startMenuVox;
    TrackSelectorVox _trackSelectorVox;
    RaceVox _raceVox;
    PauseMenuVox _pauseMenuVox;
    Array<ScreenVox*, 4> _vox;

public:
    ScreenVoxCollection();
    ~ScreenVoxCollection();

    void Init();
    ScreenVox& GetScreenVox(Screen& screen);
};
