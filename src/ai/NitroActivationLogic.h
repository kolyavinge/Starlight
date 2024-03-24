#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/ShipController.h>

class NitroActivationLogic : public Object
{
    ShipController _controller;

public:
    void Apply(Ship& ship, Track& track);
};
