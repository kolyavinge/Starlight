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
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsThrottleActive = true;
    _ship->Controls.IsBreakActive = false;
}

void ShipController::ReleaseThrottle()
{
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsThrottleActive = false;
}

void ShipController::ActivateBreak()
{
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsBreakActive = true;
    _ship->Controls.IsThrottleActive = false;
}

void ShipController::ReleaseBreak()
{
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsBreakActive = false;
}

void ShipController::TurnLeft()
{
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsTurnLeftActive = true;
    _ship->Controls.IsTurnRightActive = false;
}

void ShipController::TurnRight()
{
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsTurnRightActive = true;
    _ship->Controls.IsTurnLeftActive = false;
}

void ShipController::ReleaseTurn()
{
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsTurnLeftActive = false;
    _ship->Controls.IsTurnRightActive = false;
}

void ShipController::ActivateFire()
{
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsFireActive = true;
}

void ShipController::ReleaseFire()
{
    if (_ship->State != ShipState::Active) return;

    _ship->Controls.IsFireActive = false;
}
