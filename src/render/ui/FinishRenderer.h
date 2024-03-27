#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <render/effect/FadeEffect.h>
#include <render/common/FinishTextRenderer.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/RaceRenderer.h>

class FinishRenderer : public ScreenRenderer
{
    RaceRenderer& _raceRenderer;
    FinishTextRenderer& _finishTextRenderer;
    FadeEffect _fadeEffect;

public:
    FinishRenderer(
        RaceRenderer& raceRenderer,
        FinishTextRenderer& finishTextRenderer);

    void Activate(Screen* prevScreen) override;
    void Render(Screen& screen) override;
};

class FinishRendererResolvingFactory : public ResolvingFactory<FinishRenderer>
{
public:
    FinishRenderer* Make(Resolver& resolver) override;
};
