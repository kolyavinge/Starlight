#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <core/cm/ShipCollisionResult.h>

class ShipCollisionDetector : public Object
{
public:
    ShipCollisionResult Result;

    bool DetectCollisions(Ship& ship, IArray<Ship*>& allShips);
    bool DetectCollisions(Ship& ship, Vector3& from, Vector3& to);

private:
    bool DetectCollisions(Ship& ship1, Ship& ship2);
};
