#pragma once

#include <core/Race.h>
#include <ui/Screen.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/common/ShipRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/ui/ScreenRenderer.h>

class GameScreenRenderer : public ScreenRenderer
{
    BackgroundRenderer _backgroundRenderer;
    StarsRenderer _starsRenderer;
    ShipRenderer _shipRenderer;
    TrackRenderer _trackRenderer;

public:
    void Init() override;
    void Render(Screen& screen) override;
    void Render(Race& race);
};
