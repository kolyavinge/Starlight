#include "core/Controller.h"

Controller::Controller(Ship& ship) :
    _ship(ship)
{
}

void Controller::ActivateThrottle()
{
    _ship.IsThrottleActive = true;
    _ship.IsBreakActive = false;
}

void Controller::ReleaseThrottle()
{
    _ship.IsThrottleActive = false;
}

void Controller::ActivateBreak()
{
    _ship.IsBreakActive = true;
    _ship.IsThrottleActive = false;
}

void Controller::ReleaseBreak()
{
    _ship.IsBreakActive = false;
}

void Controller::TurnLeft()
{
    _ship.IsTurnLeftActive = true;
    _ship.IsTurnRightActive = false;
}

void Controller::TurnRight()
{
    _ship.IsTurnRightActive = true;
    _ship.IsTurnLeftActive = false;
}

void Controller::ReleaseTurn()
{
    _ship.IsTurnLeftActive = false;
    _ship.IsTurnRightActive = false;
}
