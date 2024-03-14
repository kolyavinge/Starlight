#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>
#include <render/dash/LapsCountRenderer.h>
#include <render/dash/LapTimeRenderer.h>
#include <render/dash/CompleteLapTimeRenderer.h>
#include <render/dash/CompleteLapsTimeListRenderer.h>
#include <render/dash/PlayerShipHealthRenderer.h>

class DashboardRenderer : public Object
{
    LapsCountRenderer _lapsCountRenderer;
    LapTimeRenderer _lapTimeRenderer;
    CompleteLapTimeRenderer _completeLapTimeRenderer;
    CompleteLapsTimeListRenderer _completeLapsTimeListRenderer;
    PlayerShipHealthRenderer _healthRenderer;

public:
    DashboardRenderer(TextRenderer& textRenderer);

    void Init();
    void Render(Ship& player, Laps& laps);
};