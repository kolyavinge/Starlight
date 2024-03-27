#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <ui/Screen.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipsRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/BulletsRenderer.h>
#include <render/common/EnemyShipsHealthRenderer.h>
#include <render/common/ExplosionRenderer.h>
#include <render/common/PowerUpRenderer.h>
#include <render/common/GoRenderer.h>
#include <render/dash/DashboardRenderer.h>
#include <render/ui/GraphicItemCollection.h>
#include <render/ui/ScreenRenderer.h>

class RaceRenderer : public ScreenRenderer
{
    BackgroundRenderer& _backgroundRenderer;
    StarsRenderer& _starsRenderer;
    ShipsRenderer& _shipsRenderer;
    TrackRenderer& _trackRenderer;
    BulletsRenderer& _bulletsRenderer;
    EnemyShipsHealthRenderer& _enemyShipsHealthRenderer;
    ExplosionRenderer& _explosionRenderer;
    PowerUpRenderer& _powerUpRenderer;
    DashboardRenderer& _dashboardRenderer;
    GoRenderer _goRenderer;

public:
    RaceRenderer(
        BackgroundRenderer& backgroundRenderer,
        StarsRenderer& starsRenderer,
        ShipsRenderer& shipsRenderer,
        TrackRenderer& trackRenderer,
        BulletsRenderer& bulletsRenderer,
        EnemyShipsHealthRenderer& enemyShipsHealthRenderer,
        ExplosionRenderer& explosionRenderer,
        PowerUpRenderer& powerUpRenderer,
        DashboardRenderer& dashboardRenderer);

    void Init(GraphicItemCollection& graphicItemCollection) override;
    void Activate(Screen* prevScreen) override;
    void Render(Screen& screen) override;
    void Render(Race& race);
};

class RaceRendererResolvingFactory : public ResolvingFactory<RaceRenderer>
{
public:
    RaceRenderer* Make(Resolver& resolver) override;
};
