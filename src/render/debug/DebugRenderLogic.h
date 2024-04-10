#pragma once

#include <ui/Screen.h>
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
    void Render(Screen& screen);

private:
    void RenderAxis();
    void RenderGrid();
};
