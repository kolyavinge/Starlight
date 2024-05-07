#include <render/dash/DashboardRenderer.h>

DashboardRenderer::DashboardRenderer(
    LapsCountRenderer& lapsCountRenderer,
    LapTimeRenderer& lapTimeRenderer,
    CompleteLapTimeRenderer& completeLapTimeRenderer,
    CompleteLapsTimeListRenderer& completeLapsTimeListRenderer,
    DamageEffectRenderer& damageEffectRenderer,
    EnemyShipMarkRenderer& enemyShipMarkRenderer,
    HealthRenderer& healthRenderer,
    BulletsCountRenderer& bulletsCountRenderer,
    NitroCountRenderer& nitroCountRenderer,
    RacePositionRenderer& racePositionRenderer,
    MirrorViewRenderer& mirrorViewRenderer) :
    _lapsCountRenderer(lapsCountRenderer),
    _lapTimeRenderer(lapTimeRenderer),
    _completeLapTimeRenderer(completeLapTimeRenderer),
    _completeLapsTimeListRenderer(completeLapsTimeListRenderer),
    _damageEffectRenderer(damageEffectRenderer),
    _enemyShipMarkRenderer(enemyShipMarkRenderer),
    _healthRenderer(healthRenderer),
    _bulletsCountRenderer(bulletsCountRenderer),
    _nitroCountRenderer(nitroCountRenderer),
    _racePositionRenderer(racePositionRenderer),
    _mirrorViewRenderer(mirrorViewRenderer)
{
}

void DashboardRenderer::Init()
{
    _completeLapTimeRenderer.Init();
    _damageEffectRenderer.Init();
}

void DashboardRenderer::Update(Ship& player)
{
    _damageEffectRenderer.Update(player);
}

void DashboardRenderer::Render(Ship& player, Collection<Ship*>& allShips, Track& track, Laps& laps)
{
    _damageEffectRenderer.Render();
    _lapsCountRenderer.Render(laps);
    _lapTimeRenderer.Render(laps);
    _completeLapTimeRenderer.Render(laps);
    _completeLapsTimeListRenderer.Render(laps);
    _healthRenderer.Render(player);
    _bulletsCountRenderer.Render(player.Weapon);
    _nitroCountRenderer.Render(player.Nitros);
    _racePositionRenderer.Render(player);
    _enemyShipMarkRenderer.Render(player, allShips, track);
    _mirrorViewRenderer.Render();
}

DashboardRenderer* DashboardRendererResolvingFactory::Make(Resolver& resolver)
{
    return new DashboardRenderer(
        resolver.Resolve<LapsCountRenderer>(),
        resolver.Resolve<LapTimeRenderer>(),
        resolver.Resolve<CompleteLapTimeRenderer>(),
        resolver.Resolve<CompleteLapsTimeListRenderer>(),
        resolver.Resolve<DamageEffectRenderer>(),
        resolver.Resolve<EnemyShipMarkRenderer>(),
        resolver.Resolve<HealthRenderer>(),
        resolver.Resolve<BulletsCountRenderer>(),
        resolver.Resolve<NitroCountRenderer>(),
        resolver.Resolve<RacePositionRenderer>(),
        resolver.Resolve<MirrorViewRenderer>());
}
