#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Ship.h>
#include <core/cm/BulletCollisionResult.h>
#include <core/cm/ShipCollisionDetector.h>

class BulletCollisionDetector : public Object
{
    ShipCollisionDetector _shipCollisionDetector;

public:
    BulletCollisionResult Result;

    BulletCollisionDetector();

    bool DetectCollisions(Ship& targetShip, IArray<Ship*>& allShips);
};
