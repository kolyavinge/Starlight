#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class VelocityCalculator : public Object
{
public:
    void CalculateVelocity(Ship& ship);
};
