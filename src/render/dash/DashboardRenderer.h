#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/Laps.h>
#include <render/dash/LapsCountRenderer.h>
#include <render/dash/LapTimeRenderer.h>
#include <render/dash/CompleteLapTimeRenderer.h>
#include <render/dash/CompleteLapsTimeListRenderer.h>
#include <render/dash/DamageEffectRenderer.h>
#include <render/dash/EnemyShipMarkRenderer.h>
#include <render/dash/HealthRenderer.h>
#include <render/dash/BulletsCountRenderer.h>
#include <render/dash/NitroCountRenderer.h>
#include <render/dash/RacePositionRenderer.h>
#include <render/dash/MirrorViewRenderer.h>

class DashboardRenderer : public Object
{
    LapsCountRenderer& _lapsCountRenderer;
    LapTimeRenderer& _lapTimeRenderer;
    CompleteLapTimeRenderer& _completeLapTimeRenderer;
    CompleteLapsTimeListRenderer& _completeLapsTimeListRenderer;
    DamageEffectRenderer& _damageEffectRenderer;
    EnemyShipMarkRenderer& _enemyShipMarkRenderer;
    HealthRenderer& _healthRenderer;
    BulletsCountRenderer& _bulletsCountRenderer;
    NitroCountRenderer& _nitroCountRenderer;
    RacePositionRenderer& _racePositionRenderer;
    MirrorViewRenderer& _mirrorViewRenderer;

public:
    DashboardRenderer(
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
        MirrorViewRenderer& mirrorViewRenderer);

    void Init();
    void Update(Ship& player);
    void Render(Ship& player, Collection<Ship*>& allShips, Track& track, Laps& laps);
};

class DashboardRendererResolvingFactory : public ResolvingFactory<DashboardRenderer>
{
public:
    DashboardRenderer* Make(Resolver& resolver) override;
};
