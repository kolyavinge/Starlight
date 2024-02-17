#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/Race.h>

class RaceInitializer : Object
{
public:
    void Init(Race& race);

private:
    void InitShip(Track& track, Ship& ship);
    void SetPlayerBehindStartFinishLine(Track& track, Ship& ship);
    void UpdateShipPosition(Track& track, Ship& ship);
};
