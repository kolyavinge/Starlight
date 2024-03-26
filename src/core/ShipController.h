#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>

class ShipController : public Object
{
    Ship* _ship;

public:
    ShipController();

    void SetShip(Ship& ship);
    void ActivateThrottle();
    void ReleaseThrottle();
    void ActivateBreak();
    void ReleaseBreak();
    void TurnLeft();
    void TurnRight();
    void ReleaseTurn();
    void ActivateFire();
    void ReleaseFire();
    void ActivateNitro();
    void Reset();
};

class ShipControllerResolvingFactory : public ResolvingFactory<ShipController>
{
public:
    ShipController* Make(Resolver& resolver) override;
};
