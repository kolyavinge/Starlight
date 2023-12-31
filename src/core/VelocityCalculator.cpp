#include <model/VelocityFunction.h>
#include <core/VelocityCalculator.h>

void VelocityCalculator::CalculateVelocity(float timeStep, Ship& ship)
{
    if (ship.IsThrottleActive)
    {
        ship.ThrottleTime += timeStep;
        if (ship.ThrottleTime > VelocityFunction::MaxThrottleTime)
        {
            ship.ThrottleTime = VelocityFunction::MaxThrottleTime;
        }
    }
    else if (ship.IsBreakActive)
    {
        ship.ThrottleTime -= 1.25f * timeStep;
        if (ship.ThrottleTime < 0.0f)
        {
            ship.ThrottleTime = 0.0f;
        }
    }
    else
    {
        ship.ThrottleTime -= 0.5f * timeStep;
        if (ship.ThrottleTime < 0.0f)
        {
            ship.ThrottleTime = 0.0f;
        }
    }

    ship.PrevVelocityValue = ship.VelocityValue;
    ship.SetCurrentVelocity();
}
