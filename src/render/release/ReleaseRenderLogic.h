#pragma once

#include <core/Game.h>
#include <render/RenderLogic.h>
#include <render/release/BackgroundRenderer.h>
#include <render/release/ShipRenderer.h>
#include <render/release/TrackRenderer.h>

class ReleaseRenderLogic : public RenderLogic
{
    BackgroundRenderer _backgroundRenderer;
    ShipRenderer _shipRenderer;
    TrackRenderer _trackRenderer;

public:
    void Render(Game& game);
};
