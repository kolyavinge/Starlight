#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>

class ShipStateLogic : public Object
{
public:
    void ProcessState(Ship& ship, Track& track);
};
