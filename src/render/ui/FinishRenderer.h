#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <render/effect/FadeEffect.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipsRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/BulletsRenderer.h>
#include <render/common/EnemyShipsHealthRenderer.h>
#include <render/common/ExplosionRenderer.h>
#include <render/common/PowerUpRenderer.h>
#include <render/common/FinishTextRenderer.h>
#include <render/dash/FinishDashboardRenderer.h>
#include <render/ui/ScreenRenderer.h>

class FinishRenderer : public ScreenRenderer
{
    Camera& _camera;
    Race& _race;
    BackgroundRenderer& _backgroundRenderer;
    StarsRenderer& _starsRenderer;
    ShipsRenderer& _shipsRenderer;
    TrackRenderer& _trackRenderer;
    BulletsRenderer& _bulletsRenderer;
    EnemyShipsHealthRenderer& _enemyShipsHealthRenderer;
    ExplosionRenderer& _explosionRenderer;
    PowerUpRenderer& _powerUpRenderer;
    FinishDashboardRenderer& _dashboardRenderer;
    FinishTextRenderer& _finishTextRenderer;
    FadeEffect _fadeEffect;

public:
    FinishRenderer(
        Camera& camera,
        Race& race,
        BackgroundRenderer& backgroundRenderer,
        StarsRenderer& starsRenderer,
        ShipsRenderer& shipsRenderer,
        TrackRenderer& trackRenderer,
        BulletsRenderer& bulletsRenderer,
        EnemyShipsHealthRenderer& enemyShipsHealthRenderer,
        ExplosionRenderer& explosionRenderer,
        PowerUpRenderer& powerUpRenderer,
        FinishDashboardRenderer& dashboardRenderer,
        FinishTextRenderer& finishTextRenderer);

    void Activate(Screen* prevScreen) override;
    void Render(Screen& screen) override;
    void Update() override;
};

class FinishRendererResolvingFactory : public ResolvingFactory<FinishRenderer>
{
public:
    FinishRenderer* Make(Resolver& resolver) override;
};
