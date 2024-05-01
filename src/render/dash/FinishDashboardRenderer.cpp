#include <render/dash/FinishDashboardRenderer.h>

FinishDashboardRenderer::FinishDashboardRenderer(
    LapsCountRenderer& lapsCountRenderer,
    LapTimeRenderer& lapTimeRenderer,
    CompleteLapTimeRenderer& completeLapTimeRenderer,
    CompleteLapsTimeListRenderer& completeLapsTimeListRenderer,
    HealthRenderer& healthRenderer,
    BulletsCountRenderer& bulletsCountRenderer,
    NitroCountRenderer& nitroCountRenderer,
    RacePositionRenderer& racePositionRenderer) :
    _lapsCountRenderer(lapsCountRenderer),
    _lapTimeRenderer(lapTimeRenderer),
    _completeLapTimeRenderer(completeLapTimeRenderer),
    _completeLapsTimeListRenderer(completeLapsTimeListRenderer),
    _healthRenderer(healthRenderer),
    _bulletsCountRenderer(bulletsCountRenderer),
    _nitroCountRenderer(nitroCountRenderer),
    _racePositionRenderer(racePositionRenderer)
{
}

void FinishDashboardRenderer::Render(Ship& player, Laps& laps)
{
    _lapsCountRenderer.Render(laps);
    _lapTimeRenderer.Render(laps);
    _completeLapTimeRenderer.Render(laps);
    _completeLapsTimeListRenderer.Render(laps);
    _healthRenderer.Render(player);
    _bulletsCountRenderer.Render(player.Weapon);
    _nitroCountRenderer.Render(player.Nitros);
    _racePositionRenderer.Render(player);
}

FinishDashboardRenderer* FinishDashboardRendererResolvingFactory::Make(Resolver& resolver)
{
    return new FinishDashboardRenderer(
        resolver.Resolve<LapsCountRenderer>(),
        resolver.Resolve<LapTimeRenderer>(),
        resolver.Resolve<CompleteLapTimeRenderer>(),
        resolver.Resolve<CompleteLapsTimeListRenderer>(),
        resolver.Resolve<HealthRenderer>(),
        resolver.Resolve<BulletsCountRenderer>(),
        resolver.Resolve<NitroCountRenderer>(),
        resolver.Resolve<RacePositionRenderer>());
}
