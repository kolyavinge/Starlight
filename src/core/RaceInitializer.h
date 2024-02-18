#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/PositionUpdater.h>
#include <core/Race.h>

class RaceInitializer : Object
{
    PositionUpdater _positionUpdater;

public:
    void Init(Race& race);

private:
    void InitShip(Ship& ship, Track& track);
    void SetShipBehindStartFinishLine(Ship& ship, Track& track);
};
