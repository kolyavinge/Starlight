#include <core/TurnAngleCalculator.h>

void TurnAngleCalculator::CalculateTurnAngle(Ship& ship)
{
    if (ship.IsTurnRightActive)
    {
        ship.TurnAngleRadians += ShipMeasure::TurnAngleStep;
        if (ship.TurnAngleRadians > ShipMeasure::TurnAngleThreshold) ship.TurnAngleRadians = ShipMeasure::TurnAngleThreshold;
    }
    else if (ship.IsTurnLeftActive)
    {
        ship.TurnAngleRadians -= ShipMeasure::TurnAngleStep;
        if (ship.TurnAngleRadians < -ShipMeasure::TurnAngleThreshold) ship.TurnAngleRadians = -ShipMeasure::TurnAngleThreshold;
    }
    else
    {
        if (ship.TurnAngleRadians > 0.0f)
        {
            ship.TurnAngleRadians -= ShipMeasure::TurnAngleDecay;
            if (ship.TurnAngleRadians < 0.0f) ship.TurnAngleRadians = 0.0f;
        }
        else if (ship.TurnAngleRadians < 0.0f)
        {
            ship.TurnAngleRadians += ShipMeasure::TurnAngleDecay;
            if (ship.TurnAngleRadians > 0.0f) ship.TurnAngleRadians = 0.0f;
        }
    }
}
