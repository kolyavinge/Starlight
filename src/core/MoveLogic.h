#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class MoveLogic : public Object
{
public:
    void MoveShip(float timeStep, Ship& ship);

private:
    void MoveStraight(Ship& ship, float moveDistance);
    void MoveAround(Ship& ship, float moveDistance);
    void GetPivotPoint(Ship& ship, float frontTurnRadius, float* pivotX, float* pivotY);
    void Assert(Ship& ship, float frontTurnRadius, float rearTurnRadius, float pivotX, float pivotY);
};
