#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/cm/BulletCollisionDetector.h>

class BulletCollisionProcessor : public Object
{
    BulletCollisionDetector& _bulletCollisionDetector;

public:
    BulletCollisionProcessor(BulletCollisionDetector& bulletCollisionDetector);

    bool ProcessBulletsCollisions(Ship& targetShip, Collection<Ship*>& allShips);
};

class BulletCollisionProcessorResolvingFactory : public ResolvingFactory<BulletCollisionProcessor>
{
public:
    BulletCollisionProcessor* Make(Resolver& resolver) override;
};
