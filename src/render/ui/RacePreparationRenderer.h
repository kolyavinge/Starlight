#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <render/effect/FadeEffect.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipsRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/CountdownRenderer.h>
#include <render/ui/ScreenRenderer.h>

class RacePreparationRenderer : public ScreenRenderer
{
    BackgroundRenderer& _backgroundRenderer;
    StarsRenderer& _starsRenderer;
    ShipsRenderer& _shipsRenderer;
    TrackRenderer& _trackRenderer;
    CountdownRenderer& _countdownRenderer;
    FadeEffect _fadeEffect;

public:
    RacePreparationRenderer(
        BackgroundRenderer& backgroundRenderer,
        StarsRenderer& starsRenderer,
        ShipsRenderer& shipsRenderer,
        TrackRenderer& trackRenderer,
        CountdownRenderer& countdownRenderer);

    void Activate(Screen* prevScreen) override;
    void Render(Screen& screen) override;
};

class RacePreparationRendererResolvingFactory : public ResolvingFactory<RacePreparationRenderer>
{
public:
    RacePreparationRenderer* Make(Resolver& resolver) override;
};
