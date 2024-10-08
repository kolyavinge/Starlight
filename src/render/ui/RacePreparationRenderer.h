#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Camera.h>
#include <core/Race.h>
#include <ui/Screen.h>
#include <render/effect/FadeEffect.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipsRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/PowerUpRenderer.h>
#include <render/common/CountdownRenderer.h>
#include <render/sm/ShadowMapsUpdater.h>
#include <render/sm/TrackShadowMapUpdater.h>
#include <render/sm/EmptyShadowMapInitializer.h>
#include <render/ui/ScreenRenderer.h>

class RacePreparationRenderer : public ScreenRenderer
{
    Camera& _camera;
    Race& _race;
    BackgroundRenderer& _backgroundRenderer;
    StarsRenderer& _starsRenderer;
    ShipsRenderer& _shipsRenderer;
    TrackRenderer& _trackRenderer;
    PowerUpRenderer& _powerUpRenderer;
    CountdownRenderer& _countdownRenderer;
    ShadowMapsUpdater& _shadowMapsUpdater;
    TrackShadowMapUpdater& _trackShadowMapUpdater;
    FadeEffect _fadeEffect;

public:
    RacePreparationRenderer(
        Camera& camera,
        Race& race,
        BackgroundRenderer& backgroundRenderer,
        StarsRenderer& starsRenderer,
        ShipsRenderer& shipsRenderer,
        TrackRenderer& trackRenderer,
        PowerUpRenderer& powerUpRenderer,
        CountdownRenderer& countdownRenderer,
        ShadowMapsUpdater& shadowMapsUpdater,
        TrackShadowMapUpdater& trackShadowMapUpdater,
        EmptyShadowMapInitializer& emptyShadowMapInitializer);

    void Activate(Screen* prevScreen) override;
    void Render(Screen& screen) override;
    void Update() override;
};

class RacePreparationRendererResolvingFactory : public ResolvingFactory<RacePreparationRenderer>
{
public:
    RacePreparationRenderer* Make(Resolver& resolver) override;
};
