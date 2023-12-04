#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class MoveLogic : public Object
{
public:
    void Move(float timeStep, Ship& ship);

private:
    void GetPivotPoint(Ship& ship, float frontTurnRadius, float* pivotX, float* pivotY);
    void Assert(Ship& ship, float frontTurnRadius, float rearTurnRadius, float pivotX, float pivotY);
};
