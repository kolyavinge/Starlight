#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/ShipCompletedRaceDistanceComparator.h>

class RacePositionUpdater : public Object
{
    List<Ship*> _allShips;
    ShipCompletedRaceDistanceComparator _comparator;

public:
    void Init(List<Ship*>& allShips);
    void Update();
};

class RacePositionUpdaterResolvingFactory : public ResolvingFactory<RacePositionUpdater>
{
public:
    RacePositionUpdater* Make(Resolver& resolver);
};
