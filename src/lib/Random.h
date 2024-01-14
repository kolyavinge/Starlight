#pragma once

#include <lib/Object.h>

class Random : public Object
{
public:
    Random();

    int GetIntFromZeroToN(int n);
    int GetIntFromZeroToMax();
    float GetFloatFromZeroToOne();
    float GetFloatFromZeroToN(float n);
    float GetFloatFromZeroToMax();
};
