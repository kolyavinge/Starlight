#include <vox/ScreenVoxCollection.h>

ScreenVoxCollection::ScreenVoxCollection()
{
    _vox[(int)ScreenKind::StartMenu] = &_startMenuVox;
    _vox[(int)ScreenKind::TrackSelector] = &_trackSelectorVox;
    _vox[(int)ScreenKind::PauseMenu] = &_pauseMenuVox;
    _vox[(int)ScreenKind::Race] = &_raceVox;
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
