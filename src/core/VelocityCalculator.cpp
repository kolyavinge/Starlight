#include <model/VelocityFunction.h>
#include <core/Constants.h>
#include <core/VelocityCalculator.h>

void VelocityCalculator::CalculateVelocity(Ship& ship)
{
    if (ship.IsThrottleActive)
    {
        ship.ThrottleTime += Constants::TimeStep;
        if (ship.ThrottleTime > VelocityFunction::MaxThrottleTime)
        {
            ship.ThrottleTime = VelocityFunction::MaxThrottleTime;
        }
    }
    else if (ship.IsBreakActive)
    {
        ship.ThrottleTime -= 1.25f * Constants::TimeStep;
        if (ship.ThrottleTime < 0.0f)
        {
            ship.ThrottleTime = 0.0f;
        }
    }
    else
    {
        ship.ThrottleTime -= 0.5f * Constants::TimeStep;
        if (ship.ThrottleTime < 0.0f)
        {
            ship.ThrottleTime = 0.0f;
        }
    }

    ship.PrevVelocityValue = ship.VelocityValue;
    ship.SetCurrentVelocity();
}
