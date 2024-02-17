#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <core/ShipController.h>

class SteeringLogic : public Object
{
    ShipController _controller;

public:
    void Update(Ship& ship);
};
