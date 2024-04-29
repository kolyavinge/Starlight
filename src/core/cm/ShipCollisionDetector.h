#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <model/Ship.h>

class ShipCollisionResult : public Object
{
public:
    Ship* Ship1;
    Ship* Ship2;

    ShipCollisionResult();

    void Init();
};

class ShipCollisionDetector : public Object
{
public:
    ShipCollisionResult Result;

    bool DetectCollisions(Ship& ship, Collection<Ship*>& allShips);
    bool DetectCollisions(Ship& ship1, Ship& ship2);
    bool DetectCollisions(Ship& ship, Vector3& from, Vector3& to, float stepSize = 0.1f);
    bool DetectCollisions(Ship& ship, Vector3& point);

private:
    bool CheckBordersZ(Ship& ship, Vector3& point);
};

class ShipCollisionDetectorResolvingFactory : public ResolvingFactory<ShipCollisionDetector>
{
public:
    ShipCollisionDetector* Make(Resolver& resolver) override;
};
