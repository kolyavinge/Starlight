#include <vox/StartMenuVox.h>
#include <vox/TrackSelectorVox.h>
#include <vox/PauseMenuVox.h>
#include <vox/RaceVox.h>
#include <vox/ScreenVoxCollection.h>

ScreenVoxCollection::ScreenVoxCollection()
{
    StartMenuVox* startMenuVox = new StartMenuVox();
    TrackSelectorVox* trackSelectorVox = new TrackSelectorVox();
    PauseMenuVox* pauseMenuVox = new PauseMenuVox();
    RaceVox* raceVox = new RaceVox();

    _vox[(int)ScreenKind::StartMenu] = startMenuVox;
    _vox[(int)ScreenKind::TrackSelector] = trackSelectorVox;
    _vox[(int)ScreenKind::PauseMenu] = pauseMenuVox;
    _vox[(int)ScreenKind::Race] = raceVox;
}

ScreenVoxCollection::~ScreenVoxCollection()
{
    for (int i = 0; i < _vox.Count; i++)
    {
        delete _vox[i];
    }
}

void ScreenVoxCollection::Init()
{
    _sampleCollection.Init();
    for (int i = 0; i < _vox.Count; i++)
    {
        _vox[i]->Init(_sampleCollection);
    }
}

ScreenVox& ScreenVoxCollection::GetScreenVox(Screen& screen)
{
    return *_vox[(int)screen.Kind];
}
