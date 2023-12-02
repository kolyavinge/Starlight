#include "core/TurnAngleCalculator.h"

void TurnAngleCalculator::CalculateTurnAngle(Ship& ship)
{
    if (ship.IsTurnLeftActive)
    {
        ship.TurnAngle += Ship::TurnAngleStep;
        if (ship.TurnAngle > Ship::TurnAngleThreshold) ship.TurnAngle = Ship::TurnAngleThreshold;
    }
    else if (ship.IsTurnRightActive)
    {
        ship.TurnAngle -= Ship::TurnAngleStep;
        if (ship.TurnAngle < Ship::TurnAngleThreshold) ship.TurnAngle = -Ship::TurnAngleThreshold;
    }
    else
    {
        if (ship.TurnAngle > 0.0f)
        {
            ship.TurnAngle -= Ship::TurnAngleDecay;
            if (ship.TurnAngle < 0.0f) ship.TurnAngle = 0.0f;
        }
        else if (ship.TurnAngle < 0.0f)
        {
            ship.TurnAngle += Ship::TurnAngleDecay;
            if (ship.TurnAngle > 0.0f) ship.TurnAngle = 0.0f;
        }
    }
}
