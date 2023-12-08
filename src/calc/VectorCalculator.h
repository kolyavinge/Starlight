#pragma once

#include "lib/Object.h"

class VectorCalculator : public Object
{
public:
    void GetNormalVector2d(
        float fromX, float fromY,
        float toX, float toY,
        float* resultX, float* resultY);
};
