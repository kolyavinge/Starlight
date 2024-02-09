#pragma once

#include <lib/Object.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>
#include <render/common/LapsCountRenderer.h>
#include <render/common/LapTimeRenderer.h>

class DashboardRenderer : public Object
{
    LapsCountRenderer _lapsCountRenderer;
    LapTimeRenderer _lapTimeRenderer;

public:
    DashboardRenderer(TextRenderer& textRenderer);

    void Render(Laps& laps);
};
