#pragma once

#include <lib/Object.h>

class VelocityFunction : public Object
{
public:
    inline static const float MaxThrottleTime = 12.0f;
    float MaxVelocity;

    VelocityFunction();
    float GetValue(float throttleTime);
};
