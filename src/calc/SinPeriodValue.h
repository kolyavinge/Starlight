#pragma once

#include <lib/Object.h>

class SinPeriodValue : public Object
{
    float _radians;

public:
    SinPeriodValue();

    float GetRadians();
    void SetRadians(float value);
    void Update(float step);
    float GetValue();
    float GetAbsValue();
};
