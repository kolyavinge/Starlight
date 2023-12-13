#pragma once

#include <lib/Object.h>
#include <model/Ship.h>

class DebugShipRenderer : public Object
{
public:
    void Render(Ship& ship);

private:
    void RenderMiddleLine(Ship& ship);
    void RenderTurnAngle(Ship& ship);
    void RenderBorder(Ship& ship);
    void RenderBorderPoints(Ship& ship);
    float GetAngleBetweenShipAndYStraight(Ship& ship);
};
