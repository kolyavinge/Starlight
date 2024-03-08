#pragma once

#include <lib/Object.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>
#include <render/dash/LapsCountRenderer.h>
#include <render/dash/LapTimeRenderer.h>
#include <render/dash/CompleteLapTimeRenderer.h>
#include <render/dash/CompleteLapsTimeListRenderer.h>

class DashboardRenderer : public Object
{
    LapsCountRenderer _lapsCountRenderer;
    LapTimeRenderer _lapTimeRenderer;
    CompleteLapTimeRenderer _completeLapTimeRenderer;
    CompleteLapsTimeListRenderer _completeLapsTimeListRenderer;

public:
    DashboardRenderer(TextRenderer& textRenderer);

    void Init();
    void Render(Laps& laps);
};
