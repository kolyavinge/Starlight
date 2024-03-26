#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <core/cm/BulletCollisionDetector.h>

class BulletCollisionProcessor : public Object
{
    BulletCollisionDetector _bulletCollisionDetector;

public:
    bool ProcessBulletsCollisions(Ship& targetShip, IArray<Ship*>& allShips);
};

class BulletCollisionProcessorResolvingFactory : public ResolvingFactory<BulletCollisionProcessor>
{
public:
    BulletCollisionProcessor* Make(Resolver& resolver) override;
};
