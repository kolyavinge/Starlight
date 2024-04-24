#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>

class RaceDistanceCalculator : public Object
{
public:
    void InitBeforeStart(IArray<Ship*>& allShips, Track& track);
    void CalculateRaceDistance(Ship& ship, Track& track);
};

class RaceDistanceCalculatorResolvingFactory : public ResolvingFactory<RaceDistanceCalculator>
{
public:
    RaceDistanceCalculator* Make(Resolver& resolver);
};
