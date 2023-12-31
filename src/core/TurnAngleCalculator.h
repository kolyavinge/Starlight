#pragma once

#include <lib/Object.h>
#include <model/Ship.h>

class TurnAngleCalculator : public Object
{
public:
    void CalculateTurnAngle(Ship& ship);

private:
    float GetMaxTurnAngle(Ship& ship);
};
