#pragma once

#include <lib/Object.h>
#include <model/Ship.h>

class ShipStateLogic : public Object
{
public:

    void ProcessState(Ship& ship);
};
