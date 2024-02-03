#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <ui/Screen.h>
#include <vox/SampleCollection.h>
#include <vox/ScreenVox.h>
#include <vox/StartMenuVox.h>
#include <vox/TrackSelectorVox.h>
#include <vox/PauseMenuVox.h>
#include <vox/RaceVox.h>

class ScreenVoxCollection : public Object
{
    SampleCollection _sampleCollection;
    StartMenuVox _startMenuVox;
    TrackSelectorVox _trackSelectorVox;
    PauseMenuVox _pauseMenuVox;
    RaceVox _raceVox;
    Array<ScreenVox*, 4> _vox;

public:
    ScreenVoxCollection();
    ~ScreenVoxCollection();

    void Init();
    ScreenVox& GetScreenVox(Screen& screen);
};
