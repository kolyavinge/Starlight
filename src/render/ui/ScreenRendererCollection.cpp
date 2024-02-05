#include <render/ui/ScreenRendererCollection.h>

ScreenRendererCollection::ScreenRendererCollection() :
    _startMenuRenderer(_menuBackgroundRenderer),
    _trackSelectorRenderer(_menuBackgroundRenderer),
    _racePreparationRenderer(_backgroundRenderer, _starsRenderer, _shipRenderer, _trackRenderer),
    _raceRenderer(_backgroundRenderer, _starsRenderer, _shipRenderer, _trackRenderer),
    _pauseMenuRenderer(_raceRenderer)
{
    _renderers[(int)ScreenKind::StartMenu] = &_startMenuRenderer;
    _renderers[(int)ScreenKind::TrackSelector] = &_trackSelectorRenderer;
    _renderers[(int)ScreenKind::RacePreparation] = &_racePreparationRenderer;
    _renderers[(int)ScreenKind::Race] = &_raceRenderer;
    _renderers[(int)ScreenKind::PauseMenu] = &_pauseMenuRenderer;
}

ScreenRendererCollection::~ScreenRendererCollection()
{
    for (int i = 0; i < _renderers.Count; i++)
    {
        delete _renderers[i];
    }
}

void ScreenRendererCollection::Init()
{
    _backgroundRenderer.Init();
    _menuBackgroundRenderer.Init();
    _shipRenderer.Init();
    _menuItemCollection.Init();
    for (int i = 0; i < _renderers.Count; i++)
    {
        _renderers[i]->Init(_menuItemCollection);
    }
}

ScreenRenderer& ScreenRendererCollection::GetScreenRenderer(Screen& screen)
{
    return *_renderers[(int)screen.Kind];
}
