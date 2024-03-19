#pragma once

#include <lib/Object.h>

class VelocityFunction : public Object
{
    float _delta;

public:
    inline static const float MaxThrottleTime = 20.0f;
    float MaxVelocity;

    VelocityFunction();

    float GetValueByThrottleTime(float throttleTime);
    float GetThrottleTimeByValue(float value);
    void SetDelta(float delta);
};
