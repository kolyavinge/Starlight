#pragma once

#include <calc/Vector3d.h>

class VectorCalculator
{
public:
    static void GetNormalVector2d(
        float fromX, float fromY,
        float toX, float toY,
        float* resultX, float* resultY);
    static void GetNormalVector3d(Vector3d& center, Vector3d right, Vector3d front, Vector3d& result);
    static bool IsSameDirection(Vector3d& base, Vector3d v1, Vector3d v2);
};
