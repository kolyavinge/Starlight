#include <core/Constants.h>
#include <core/VelocityCalculator.h>

void VelocityCalculator::CalculateVelocity(Ship& ship)
{
    if (ship.Controls.IsThrottleActive)
    {
        ship.ThrottleTime += Constants::TimeStep;
        if (ship.ThrottleTime > ship.VelocityFunction.MaxThrottleTime)
        {
            ship.ThrottleTime = ship.VelocityFunction.MaxThrottleTime;
        }
    }
    else if (ship.Controls.IsBreakActive)
    {
        ship.ThrottleTime -= 2.0f * Constants::TimeStep;
        if (ship.ThrottleTime < 0.0f)
        {
            ship.ThrottleTime = 0.0f;
        }
    }
    else
    {
        ship.ThrottleTime -= 1.0f * Constants::TimeStep;
        if (ship.ThrottleTime < 0.0f)
        {
            ship.ThrottleTime = 0.0f;
        }
    }

    ship.PrevVelocityValue = ship.VelocityValue;
    ship.VelocityValue = ship.VelocityFunction.GetValueByThrottleTime(ship.ThrottleTime);
}

VelocityCalculator* VelocityCalculatorResolvingFactory::Make(Resolver&)
{
    return new VelocityCalculator();
}
