#pragma once

#include <lib/Object.h>

class VelocityFunction : public Object
{
    float _delta;

public:
    const float MaxThrottleTime;
    const float InitMaxVelocity;
    float MaxVelocity;

    VelocityFunction();

    void Init();
    float GetValueByThrottleTime(float throttleTime);
    float GetThrottleTimeByValue(float value);
    void AddDelta(float delta);
};
