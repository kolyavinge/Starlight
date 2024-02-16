#include <render/ui/ScreenRendererCollection.h>

ScreenRendererCollection::ScreenRendererCollection() :
    _menuBackgroundRenderer(_backgroundRenderer, _starsRenderer),
    _dashboardRenderer(_textRenderer),
    _startMenuRenderer(_menuBackgroundRenderer),
    _trackSelectorRenderer(_menuBackgroundRenderer),
    _racePreparationRenderer(_backgroundRenderer, _starsRenderer, _shipRenderer, _trackRenderer),
    _raceRenderer(_backgroundRenderer, _starsRenderer, _shipRenderer, _trackRenderer, _dashboardRenderer),
    _pauseMenuRenderer(_raceRenderer),
    _finishRenderer(_raceRenderer)
{
    _renderers[(int)ScreenKind::StartMenu] = &_startMenuRenderer;
    _renderers[(int)ScreenKind::TrackSelector] = &_trackSelectorRenderer;
    _renderers[(int)ScreenKind::RacePreparation] = &_racePreparationRenderer;
    _renderers[(int)ScreenKind::Race] = &_raceRenderer;
    _renderers[(int)ScreenKind::PauseMenu] = &_pauseMenuRenderer;
    _renderers[(int)ScreenKind::Finish] = &_finishRenderer;
}

void ScreenRendererCollection::Init()
{
    _textRenderer.Init();
    _backgroundRenderer.Init();
    _shipRenderer.Init();
    _graphicItemCollection.Init();
    for (int i = 0; i < _renderers.Count; i++)
    {
        _renderers[i]->Init(_graphicItemCollection);
    }
}

ScreenRenderer& ScreenRendererCollection::GetScreenRenderer(Screen& screen)
{
    return *_renderers[(int)screen.Kind];
}
