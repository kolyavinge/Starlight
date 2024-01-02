#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <render/ShipMesh.h>

class DebugShipRenderer : public Object
{
    ShipMesh _shipMesh;

public:
    void Render(Ship& ship, Track& track);

private:
    void RenderMiddleLine(Ship& ship);
    void RenderTurnAngle(Ship& ship);
    void RenderDeviation(Ship& ship);
    void RenderBorder(Ship& ship);
    void RenderBorderPoints(Ship& ship);
    void RenderTrackPoints(Ship& ship, Track& track);
    float GetAngleBetweenShipAndYStraight(Ship& ship);
};
