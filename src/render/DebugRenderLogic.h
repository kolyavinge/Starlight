#pragma once

#include "lib/Object.h"
#include "core/Game.h"
#include "render/DebugShipRenderer.h"
#include "render/DebugTrackRenderer.h"

class DebugRenderLogic : public Object
{
    DebugShipRenderer _shipRenderer;
    DebugTrackRenderer _trackRenderer;

public:
    void Render(Game& game);

private:
    void RenderAxis();
    void RenderGrid();
};
