#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
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

    bool DetectCollisions(Ship& ship, Collection<PowerUp>& powerUps);
};

class PowerUpCollisionDetectorResolvingFactory : public ResolvingFactory<PowerUpCollisionDetector>
{
public:
    PowerUpCollisionDetector* Make(Resolver& resolver) override;
};
