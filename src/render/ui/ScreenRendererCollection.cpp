#include <ui/ScreenKind.h>
#include <render/ui/ScreenRendererCollection.h>

ScreenRendererCollection::ScreenRendererCollection() :
    _menuBackgroundRenderer(_backgroundRenderer, _starsRenderer),
    _explosionRenderer(_graphicItemCollection.ExplosionTexture),
    _dashboardRenderer(_textRenderer),
    _startMenuRenderer(_menuBackgroundRenderer),
    _trackSelectorRenderer(_menuBackgroundRenderer),
    _racePreparationRenderer(_backgroundRenderer, _starsRenderer, _shipsRenderer, _trackRenderer),
    _raceRenderer(
        _backgroundRenderer,
        _starsRenderer,
        _shipsRenderer,
        _trackRenderer,
        _bulletsRenderer,
        _enemyShipsHealthRenderer,
        _explosionRenderer,
        _dashboardRenderer),
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
    _graphicItemCollection.Init();
    _textRenderer.Init();
    _backgroundRenderer.Init();
    _shipsRenderer.Init();
    for (int i = 0; i < _renderers.GetCount(); i++)
    {
        _renderers[i]->Init(_graphicItemCollection);
    }
}

ScreenRenderer& ScreenRendererCollection::GetScreenRenderer(Screen& screen)
{
    return *_renderers[(int)screen.Kind];
}
