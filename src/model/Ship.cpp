#include "model/Ship.h"

Ship::Ship()
{
    Init();
}

void Ship::Init()
{
    IsThrottleActive = false;
    IsBreakActive = false;
    IsTurnLeftActive = false;
    IsTurnRightActive = false;
    Throttle = 0;
    TurnAngle = 0;
}
