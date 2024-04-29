#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
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
    ShipCollisionDetector& _shipCollisionDetector;

public:
    BulletCollisionResult Result;

    BulletCollisionDetector(ShipCollisionDetector& shipCollisionDetector);

    bool DetectCollisions(Ship& targetShip, Collection<Ship*>& allShips);
};

class BulletCollisionDetectorResolvingFactory : public ResolvingFactory<BulletCollisionDetector>
{
public:
    BulletCollisionDetector* Make(Resolver& resolver) override;
};
