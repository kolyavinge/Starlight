#include <lib/Math.h>
#include <lib/Numeric.h>
#include <model/VelocityFunction.h>

float VelocityFunction::GetValue(float throttleTime)
{
    if (Numeric::FloatEquals(throttleTime, 0.0f)) return 0.0f;
    if (throttleTime >= MaxThrottleTime) throttleTime = MaxThrottleTime;

    return 1.5f * Math::LogE(throttleTime + 1.0f);
}
