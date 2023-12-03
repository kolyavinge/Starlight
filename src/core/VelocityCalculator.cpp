#include "core/VelocityCalculator.h"

void VelocityCalculator::CalculateVelocity(float timeStep, Ship& ship)
{
    if (ship.IsThrottleActive)
    {
        ship.ThrottleTime += timeStep;
        if (ship.ThrottleTime > Ship::ThrottleTimeThreshold) ship.ThrottleTime = Ship::ThrottleTimeThreshold;
    }
    else if (ship.IsBreakActive)
    {
        ship.ThrottleTime -= 2.0f * timeStep;
        if (ship.ThrottleTime < 0.0f) ship.ThrottleTime = 0.0f;
    }
    else
    {
        ship.ThrottleTime -= 0.25f * timeStep;
        if (ship.ThrottleTime < 0.0f) ship.ThrottleTime = 0.0f;
    }

    ship.LastVelocityValue = ship.CurrentVelocityValue;
    ship.CurrentVelocityValue = ship.GetCurrentVelocity();
}
