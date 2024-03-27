#include <render/dash/DashboardRenderer.h>

DashboardRenderer::DashboardRenderer(
    LapsCountRenderer& lapsCountRenderer,
    LapTimeRenderer& lapTimeRenderer,
    CompleteLapTimeRenderer& completeLapTimeRenderer,
    CompleteLapsTimeListRenderer& completeLapsTimeListRenderer,
    PlayerShipHealthRenderer& healthRenderer,
    BulletsCountRenderer& bulletsCountRenderer,
    NitroCountRenderer& nitroCountRenderer) :
    _lapsCountRenderer(lapsCountRenderer),
    _lapTimeRenderer(lapTimeRenderer),
    _completeLapTimeRenderer(completeLapTimeRenderer),
    _completeLapsTimeListRenderer(completeLapsTimeListRenderer),
    _healthRenderer(healthRenderer),
    _bulletsCountRenderer(bulletsCountRenderer),
    _nitroCountRenderer(nitroCountRenderer)
{
}

void DashboardRenderer::Init()
{
    _completeLapTimeRenderer.Init();
}

void DashboardRenderer::Render(Ship& player, Laps& laps)
{
    _lapsCountRenderer.Render(laps);
    _lapTimeRenderer.Render(laps);
    _completeLapTimeRenderer.Render(laps);
    _completeLapsTimeListRenderer.Render(laps);
    _healthRenderer.Render(player);
    _bulletsCountRenderer.Render(player.Weapon);
    _nitroCountRenderer.Render(player.Nitros);
}

DashboardRenderer* DashboardRendererResolvingFactory::Make(Resolver& resolver)
{
    return new DashboardRenderer(
        resolver.Resolve<LapsCountRenderer>(),
        resolver.Resolve<LapTimeRenderer>(),
        resolver.Resolve<CompleteLapTimeRenderer>(),
        resolver.Resolve<CompleteLapsTimeListRenderer>(),
        resolver.Resolve<PlayerShipHealthRenderer>(),
        resolver.Resolve<BulletsCountRenderer>(),
        resolver.Resolve<NitroCountRenderer>());
}
