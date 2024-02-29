#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <model/Ship.h>
#include <core/ShipCollisionResult.h>

class ShipCollisionDetector : public Object
{
public:
    ShipCollisionResult Result;

    bool DetectCollisions(Ship& ship, List<Ship*>& allShips);

private:
    bool DetectCollisions(Ship& ship1, Ship& ship2);
};
