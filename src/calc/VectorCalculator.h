#pragma once

#include <calc/Vector3d.h>

class VectorCalculator
{
public:
    static void GetNormalVector2d(
        float fromX, float fromY,
        float toX, float toY,
        float* resultX, float* resultY);
    static void GetNormalVector3d(Vector3d& v1, Vector3d& v2, Vector3d& v3, Vector3d& result);
};
