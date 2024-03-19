#include <lib/Math.h>
#include <lib/Numeric.h>
#include <model/VelocityFunction.h>

VelocityFunction::VelocityFunction()
{
    _delta = 0.0f;
    MaxVelocity = GetValueByThrottleTime(MaxThrottleTime);
}

float VelocityFunction::GetValueByThrottleTime(float throttleTime)
{
    if (Numeric::FloatEquals(throttleTime, 0.0f)) return 0.0f;
    if (throttleTime >= MaxThrottleTime) throttleTime = MaxThrottleTime;

    return (5.5f + _delta) * Math::LogE(throttleTime + 1.0f);
}

float VelocityFunction::GetThrottleTimeByValue(float value)
{
    if (value > MaxVelocity) return MaxThrottleTime;

    return Math::Power(Math::E, (1.0f / (5.5f + _delta)) * value) - 1.0f;
}

void VelocityFunction::SetDelta(float delta)
{
    _delta = delta;
    MaxVelocity = GetValueByThrottleTime(MaxThrottleTime);
}
