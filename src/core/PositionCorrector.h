#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class PositionCorrector : public Object
{
public:
    void CorrectAfterFloatOperations(Ship& ship);
};
