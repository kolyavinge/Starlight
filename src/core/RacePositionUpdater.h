#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/ShipCompletedRaceDistanceComparator.h>

class RacePositionUpdater : public Object
{
    ShipCompletedRaceDistanceComparator _comparator;

public:
    void Update(Collection<Ship*>& allShips);
};

class RacePositionUpdaterResolvingFactory : public ResolvingFactory<RacePositionUpdater>
{
public:
    RacePositionUpdater* Make(Resolver& resolver);
};
