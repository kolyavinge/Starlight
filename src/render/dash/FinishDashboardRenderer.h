#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/Laps.h>
#include <render/dash/LapsCountRenderer.h>
#include <render/dash/LapTimeRenderer.h>
#include <render/dash/CompleteLapTimeRenderer.h>
#include <render/dash/CompleteLapsTimeListRenderer.h>
#include <render/dash/HealthRenderer.h>
#include <render/dash/BulletsCountRenderer.h>
#include <render/dash/NitroCountRenderer.h>
#include <render/dash/RacePositionRenderer.h>

class FinishDashboardRenderer : public Object
{
    LapsCountRenderer& _lapsCountRenderer;
    LapTimeRenderer& _lapTimeRenderer;
    CompleteLapTimeRenderer& _completeLapTimeRenderer;
    CompleteLapsTimeListRenderer& _completeLapsTimeListRenderer;
    HealthRenderer& _healthRenderer;
    BulletsCountRenderer& _bulletsCountRenderer;
    NitroCountRenderer& _nitroCountRenderer;
    RacePositionRenderer& _racePositionRenderer;

public:
    FinishDashboardRenderer(
        LapsCountRenderer& lapsCountRenderer,
        LapTimeRenderer& lapTimeRenderer,
        CompleteLapTimeRenderer& completeLapTimeRenderer,
        CompleteLapsTimeListRenderer& completeLapsTimeListRenderer,
        HealthRenderer& healthRenderer,
        BulletsCountRenderer& bulletsCountRenderer,
        NitroCountRenderer& nitroCountRenderer,
        RacePositionRenderer& racePositionRenderer);

    void Render(Ship& player, Laps& laps);
};

class FinishDashboardRendererResolvingFactory : public ResolvingFactory<FinishDashboardRenderer>
{
public:
    FinishDashboardRenderer* Make(Resolver& resolver) override;
};
