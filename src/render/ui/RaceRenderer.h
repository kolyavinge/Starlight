#pragma once

#include <core/Race.h>
#include <ui/Screen.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/GoRenderer.h>
#include <render/common/DashboardRenderer.h>
#include <render/ui/GraphicItemCollection.h>
#include <render/ui/ScreenRenderer.h>

class RaceRenderer : public ScreenRenderer
{
    BackgroundRenderer& _backgroundRenderer;
    StarsRenderer& _starsRenderer;
    ShipRenderer& _shipRenderer;
    TrackRenderer& _trackRenderer;
    GoRenderer _goRenderer;
    DashboardRenderer& _dashboardRenderer;

public:
    RaceRenderer(
        BackgroundRenderer& backgroundRenderer,
        StarsRenderer& starsRenderer,
        ShipRenderer& shipRenderer,
        TrackRenderer& trackRenderer,
        DashboardRenderer& dashboardRenderer);

    void Init(GraphicItemCollection& graphicItemCollection) override;
    void Activate(Screen* prevScreen) override;
    void Render(Screen& screen) override;
    void Render(Race& race);
};
