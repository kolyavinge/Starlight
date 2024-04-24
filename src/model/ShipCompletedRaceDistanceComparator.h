#pragma once

#include <lib/Object.h>
#include <lib/IComparator.h>
#include <model/Ship.h>

class ShipCompletedRaceDistanceComparator : public Object, public IComparator<Ship*>
{
public:
    int Compare(Ship* a, Ship* b) override;
};
