#include <lib/Math.h>
#include <lib/Numeric.h>
#include <model/VelocityFunction.h>

VelocityFunction::VelocityFunction()
{
    MaxVelocity = GetValue(MaxThrottleTime);
}

float VelocityFunction::GetValue(float throttleTime)
{
    if (Numeric::FloatEquals(throttleTime, 0.0f)) return 0.0f;
    if (throttleTime >= MaxThrottleTime) throttleTime = MaxThrottleTime;

    return 4.5f * Math::LogE(throttleTime + 1.0f);
}
