#pragma once

#include <ui/Screen.h>
#include <render/effect/FadeEffect.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/ui/GraphicItemCollection.h>
#include <render/ui/ScreenRenderer.h>

class RacePreparationRenderer : public ScreenRenderer
{
    BackgroundRenderer& _backgroundRenderer;
    StarsRenderer& _starsRenderer;
    ShipRenderer& _shipRenderer;
    TrackRenderer& _trackRenderer;
    FadeEffect _fadeEffect;

public:
    RacePreparationRenderer(
        BackgroundRenderer& backgroundRenderer,
        StarsRenderer& starsRenderer,
        ShipRenderer& shipRenderer,
        TrackRenderer& trackRenderer);

    void Init(GraphicItemCollection& graphicItemCollection) override;
    void Activate() override;
    void Render(Screen& screen) override;
};
