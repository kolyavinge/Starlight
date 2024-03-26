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
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsThrottleActive = true;
    _ship->Controls.IsBreakActive = false;
}

void ShipController::ReleaseThrottle()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsThrottleActive = false;
}

void ShipController::ActivateBreak()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsBreakActive = true;
    _ship->Controls.IsThrottleActive = false;
}

void ShipController::ReleaseBreak()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsBreakActive = false;
}

void ShipController::TurnLeft()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsTurnLeftActive = true;
    _ship->Controls.IsTurnRightActive = false;
}

void ShipController::TurnRight()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsTurnRightActive = true;
    _ship->Controls.IsTurnLeftActive = false;
}

void ShipController::ReleaseTurn()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsTurnLeftActive = false;
    _ship->Controls.IsTurnRightActive = false;
}

void ShipController::ActivateFire()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsFireActive = true;
}

void ShipController::ReleaseFire()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsFireActive = false;
}

void ShipController::ActivateNitro()
{
    if (!_ship->CanControlled()) return;

    _ship->Controls.IsNitroActive = true;
}

void ShipController::Reset()
{
    _ship->Reset();
}

ShipController* ShipControllerResolvingFactory::Make(Resolver&)
{
    return new ShipController();
}
