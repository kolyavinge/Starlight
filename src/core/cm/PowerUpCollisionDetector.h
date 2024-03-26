#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/PowerUp.h>
#include <core/cm/ShipCollisionDetector.h>

class PowerUpCollisionResult : public Object
{
public:
    List<PowerUp*> PowerUps;

    void Init();
};

class PowerUpCollisionDetector : public Object
{
    ShipCollisionDetector& _shipCollisionDetector;

public:
    PowerUpCollisionResult Result;

    PowerUpCollisionDetector(ShipCollisionDetector& shipCollisionDetector);

    bool DetectCollisions(Ship& ship, IArray<PowerUp>& powerUps);
};

class PowerUpCollisionDetectorResolvingFactory : public ResolvingFactory<PowerUpCollisionDetector>
{
public:
    PowerUpCollisionDetector* Make(Resolver& resolver) override;
};
