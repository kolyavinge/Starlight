#pragma once

#include <core/Game.h>
#include <render/RenderLogic.h>
#include <render/DebugShipRenderer.h>
#include <render/DebugTrackRenderer.h>

class DebugRenderLogic : public RenderLogic
{
    DebugShipRenderer _shipRenderer;
    DebugTrackRenderer _trackRenderer;

public:
    void Render(Game& game);

private:
    void RenderAxis();
    void RenderGrid();
};
