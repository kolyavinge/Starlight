#pragma once

#include <core/Game.h>
#include <render/debug/DebugBackgroundRenderer.h>
#include <render/debug/DebugShipRenderer.h>
#include <render/debug/DebugTrackRenderer.h>
#include <render/ui/ScreenRenderer.h>

class DebugRenderLogic : public ScreenRenderer
{
    DebugBackgroundRenderer _backgroundRenderer;
    DebugShipRenderer _shipRenderer;
    DebugTrackRenderer _trackRenderer;

public:
    void Init();
    void Render(Game& game);

private:
    void RenderAxis();
    void RenderGrid();
};
