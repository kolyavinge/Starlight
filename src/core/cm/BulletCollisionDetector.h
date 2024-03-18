#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/List.h>
#include <model/Ship.h>
#include <model/Bullet.h>
#include <core/cm/ShipCollisionDetector.h>

class BulletCollisionResult : public Object
{
public:
    List<Bullet*> Bullets;

    void Init();
};

class BulletCollisionDetector : public Object
{
    ShipCollisionDetector _shipCollisionDetector;

public:
    BulletCollisionResult Result;

    BulletCollisionDetector();

    bool DetectCollisions(Ship& targetShip, IArray<Ship*>& allShips);
};
