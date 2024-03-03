#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Ship.h>
#include <core/cm/ShipCollisionDetector.h>

class ShipCollisionProcessor : public Object
{
    ShipCollisionDetector _shipCollisionDetector;

public:
    bool ProcessShipsCollisions(Ship& ship, IArray<Ship*>& allShips);
};
