#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
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

    bool DetectCollisions(Ship& ship, IArray<Ship*>& allShips);
    bool DetectCollisions(Ship& ship, Vector3& from, Vector3& to);
    bool DetectCollisions(Ship& ship, Vector3& point);

private:
    bool DetectCollisions(Ship& ship1, Ship& ship2);
};

class ShipCollisionDetectorResolvingFactory : public ResolvingFactory<ShipCollisionDetector>
{
public:
    ShipCollisionDetector* Make(Resolver& resolver) override;
};
