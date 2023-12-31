#pragma once

#include <lib/Object.h>

class VelocityFunction : public Object
{
public:
    inline static const float MaxThrottleTime = 5.0f;
    //inline static const float MaxVelocity = 1.0f;

    float GetValue(float throttleTime);
};
