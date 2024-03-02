#include <core/ShipController.h>

ShipController::ShipController()
{
    _ship = nullptr;
}

void ShipController::SetShip(Ship& ship)
{
    _ship = &ship;
}

void ShipController::ActivateThrottle()
{
    _ship->IsThrottleActive = true;
    _ship->IsBreakActive = false;
}

void ShipController::ReleaseThrottle()
{
    _ship->IsThrottleActive = false;
}

void ShipController::ActivateBreak()
{
    _ship->IsBreakActive = true;
    _ship->IsThrottleActive = false;
}

void ShipController::ReleaseBreak()
{
    _ship->IsBreakActive = false;
}

void ShipController::TurnLeft()
{
    _ship->IsTurnLeftActive = true;
    _ship->IsTurnRightActive = false;
}

void ShipController::TurnRight()
{
    _ship->IsTurnRightActive = true;
    _ship->IsTurnLeftActive = false;
}

void ShipController::ReleaseTurn()
{
    _ship->IsTurnLeftActive = false;
    _ship->IsTurnRightActive = false;
}

void ShipController::ActivateFire()
{
    _ship->IsFireActive = true;
}

void ShipController::ReleaseFire()
{
    _ship->IsFireActive = false;
}
