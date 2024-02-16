#pragma once

#include <ui/Screen.h>
#include <render/effect/FadeEffect.h>
#include <render/common/FinishTextRenderer.h>
#include <render/ui/GraphicItemCollection.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/RaceRenderer.h>

class FinishRenderer : public ScreenRenderer
{
    RaceRenderer& _raceRenderer;
    FinishTextRenderer _finishTextRenderer;
    FadeEffect _fadeEffect;

public:
    FinishRenderer(
        RaceRenderer& raceRenderer);

    void Init(GraphicItemCollection& graphicItemCollection) override;
    void Activate(Screen* prevScreen) override;
    void Render(Screen& screen) override;
};