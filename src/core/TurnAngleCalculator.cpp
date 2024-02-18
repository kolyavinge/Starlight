#include <lib/Assert.h>
#include <lib/Numeric.h>
#include <model/ShipMeasure.h>
#include <core/TurnAngleCalculator.h>

void TurnAngleCalculator::CalculateTurnAngle(Ship& ship)
{
    if (ship.IsTurnRightActive)
    {
        float maxTurnAngle = GetMaxTurnAngle(ship);
        ship.TurnAngleRadians += ShipMeasure::TurnAngleStep;
        if (ship.TurnAngleRadians > maxTurnAngle) ship.TurnAngleRadians = maxTurnAngle;
    }
    else if (ship.IsTurnLeftActive)
    {
        float maxTurnAngle = GetMaxTurnAngle(ship);
        ship.TurnAngleRadians -= ShipMeasure::TurnAngleStep;
        if (ship.TurnAngleRadians < -maxTurnAngle) ship.TurnAngleRadians = -maxTurnAngle;
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

float TurnAngleCalculator::GetMaxTurnAngle(Ship& ship)
{
    Assert::False(Numeric::FloatEquals(ship.VelocityFunction.MaxVelocity, 0.0f));

    return ShipMeasure::MaxTurnAngle * (1.15f - ship.VelocityValue / ship.VelocityFunction.MaxVelocity);
}
