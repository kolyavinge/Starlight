#pragma once

#include "lib/Object.h"
#include "model/Ship.h"

class MoveLogic : public Object
{
public:
    void Move(Ship& ship);
};
