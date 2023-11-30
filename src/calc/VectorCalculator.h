#pragma once

#include "lib/Object.h"
#include "calc/Vector3d.h"

class VectorCalculator : public Object
{
public:
    void GetNormalVector2d(
        float from1X, float from1Y,
        float to1X, float to1Y,
        float* resultX, float* resultY);
};
