#include <ui/ScreenKind.h>
#include <render/ui/RenderManager.h>

RenderManager::RenderManager(
    StartMenuRenderer& startMenuRenderer,
    TrackSelectorRenderer& trackSelectorRenderer,
    RacePreparationRenderer& racePreparationRenderer,
    RaceRenderer& raceRenderer,
    PauseMenuRenderer& pauseMenuRenderer,
    FinishRenderer& finishRenderer) :
    _startMenuRenderer(startMenuRenderer),
    _trackSelectorRenderer(trackSelectorRenderer),
    _racePreparationRenderer(racePreparationRenderer),
    _raceRenderer(raceRenderer),
    _pauseMenuRenderer(pauseMenuRenderer),
    _finishRenderer(finishRenderer)
{
    _renderers[(int)ScreenKind::StartMenu] = &_startMenuRenderer;
    _renderers[(int)ScreenKind::TrackSelector] = &_trackSelectorRenderer;
    _renderers[(int)ScreenKind::RacePreparation] = &_racePreparationRenderer;
    _renderers[(int)ScreenKind::Race] = &_raceRenderer;
    _renderers[(int)ScreenKind::PauseMenu] = &_pauseMenuRenderer;
    _renderers[(int)ScreenKind::Finish] = &_finishRenderer;
}

ScreenRenderer& RenderManager::GetScreenRenderer(Screen& screen)
{
    return *_renderers[(int)screen.Kind];
}

RenderManager* RenderManagerResolvingFactory::Make(Resolver& resolver)
{
    return new RenderManager(
        resolver.Resolve<StartMenuRenderer>(),
        resolver.Resolve<TrackSelectorRenderer>(),
        resolver.Resolve<RacePreparationRenderer>(),
        resolver.Resolve<RaceRenderer>(),
        resolver.Resolve<PauseMenuRenderer>(),
        resolver.Resolve<FinishRenderer>());
}
