#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class CollisionDetector : public Object
{
public:
    void Detect(Ship& ship);
};
