#pragma once

#include <lib/Object.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>
#include <render/common/LapsCountRenderer.h>
#include <render/common/LapTimeRenderer.h>
#include <render/common/CompleteLapTimeRenderer.h>

class DashboardRenderer : public Object
{
    LapsCountRenderer _lapsCountRenderer;
    LapTimeRenderer _lapTimeRenderer;
    CompleteLapTimeRenderer _completeLapTimeRenderer;

public:
    DashboardRenderer(TextRenderer& textRenderer);

    void Init();
    void Render(Laps& laps);
};
