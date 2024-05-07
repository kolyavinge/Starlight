#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/Laps.h>
#include <render/dash/LapTimeRenderer.h>
#include <render/dash/CompleteLapTimeRenderer.h>
#include <render/dash/CompleteLapsTimeListRenderer.h>
#include <render/dash/RacePositionRenderer.h>

class FinishDashboardRenderer : public Object
{
    LapTimeRenderer& _lapTimeRenderer;
    CompleteLapTimeRenderer& _completeLapTimeRenderer;
    CompleteLapsTimeListRenderer& _completeLapsTimeListRenderer;
    RacePositionRenderer& _racePositionRenderer;

public:
    FinishDashboardRenderer(
        LapTimeRenderer& lapTimeRenderer,
        CompleteLapTimeRenderer& completeLapTimeRenderer,
        CompleteLapsTimeListRenderer& completeLapsTimeListRenderer,
        RacePositionRenderer& racePositionRenderer);

    void Render(Ship& player, Laps& laps);
};

class FinishDashboardRendererResolvingFactory : public ResolvingFactory<FinishDashboardRenderer>
{
public:
    FinishDashboardRenderer* Make(Resolver& resolver) override;
};
