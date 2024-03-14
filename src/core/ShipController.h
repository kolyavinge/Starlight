#pragma once

#include <lib/Object.h>
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
    void Reset();
};
