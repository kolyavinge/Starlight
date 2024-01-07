#pragma once

#include <core/Game.h>
#include <render/RenderLogic.h>
#include <render/debug/DebugBackgroundRenderer.h>
#include <render/debug/DebugShipRenderer.h>
#include <render/debug/DebugTrackRenderer.h>

class DebugRenderLogic : public RenderLogic
{
    DebugBackgroundRenderer _backgroundRenderer;
    DebugShipRenderer _shipRenderer;
    DebugTrackRenderer _trackRenderer;

public:
    void Render(Game& game);

private:
    void RenderAxis();
    void RenderGrid();
};
