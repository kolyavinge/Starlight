#include <vox/ScreenVoxCollection.h>

ScreenVoxCollection::ScreenVoxCollection()
{
    _vox[(int)ScreenKind::StartMenu] = &_startMenuVox;
    _vox[(int)ScreenKind::TrackSelector] = &_trackSelectorVox;
    _vox[(int)ScreenKind::RacePreparation] = &_racePreparationVox;
    _vox[(int)ScreenKind::Race] = &_raceVox;
    _vox[(int)ScreenKind::PauseMenu] = &_pauseMenuVox;
    _vox[(int)ScreenKind::Finish] = &_finishVox;
}

void ScreenVoxCollection::Init()
{
    _sampleCollection.Init();
    for (int i = 0; i < _vox.GetCount(); i++)
    {
        _vox[i]->Init(_sampleCollection);
    }
}

ScreenVox& ScreenVoxCollection::GetScreenVox(Screen& screen)
{
    return *_vox[(int)screen.Kind];
}
