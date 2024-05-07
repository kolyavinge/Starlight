#include <render/dash/FinishDashboardRenderer.h>

FinishDashboardRenderer::FinishDashboardRenderer(
    LapTimeRenderer& lapTimeRenderer,
    CompleteLapTimeRenderer& completeLapTimeRenderer,
    CompleteLapsTimeListRenderer& completeLapsTimeListRenderer,
    RacePositionRenderer& racePositionRenderer) :
    _lapTimeRenderer(lapTimeRenderer),
    _completeLapTimeRenderer(completeLapTimeRenderer),
    _completeLapsTimeListRenderer(completeLapsTimeListRenderer),
    _racePositionRenderer(racePositionRenderer)
{
}

void FinishDashboardRenderer::Render(Ship& player, Laps& laps)
{
    _lapTimeRenderer.Render(laps);
    _completeLapTimeRenderer.Render(laps);
    _completeLapsTimeListRenderer.Render(laps);
    _racePositionRenderer.Render(player);
}

FinishDashboardRenderer* FinishDashboardRendererResolvingFactory::Make(Resolver& resolver)
{
    return new FinishDashboardRenderer(
        resolver.Resolve<LapTimeRenderer>(),
        resolver.Resolve<CompleteLapTimeRenderer>(),
        resolver.Resolve<CompleteLapsTimeListRenderer>(),
        resolver.Resolve<RacePositionRenderer>());
}
