#include "core/TurnAngleCalculator.h"

void TurnAngleCalculator::CalculateTurnAngle(Ship& ship)
{
    if (ship.IsTurnRightActive)
    {
        ship.TurnAngleRadians += Ship::TurnAngleStep;
        if (ship.TurnAngleRadians > Ship::TurnAngleThreshold) ship.TurnAngleRadians = Ship::TurnAngleThreshold;
    }
    else if (ship.IsTurnLeftActive)
    {
        ship.TurnAngleRadians -= Ship::TurnAngleStep;
        if (ship.TurnAngleRadians < -Ship::TurnAngleThreshold) ship.TurnAngleRadians = -Ship::TurnAngleThreshold;
    }
    else
    {
        if (ship.TurnAngleRadians > 0.0f)
        {
            ship.TurnAngleRadians -= Ship::TurnAngleDecay;
            if (ship.TurnAngleRadians < 0.0f) ship.TurnAngleRadians = 0.0f;
        }
        else if (ship.TurnAngleRadians < 0.0f)
        {
            ship.TurnAngleRadians += Ship::TurnAngleDecay;
            if (ship.TurnAngleRadians > 0.0f) ship.TurnAngleRadians = 0.0f;
        }
    }
}
