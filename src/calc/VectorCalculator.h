#pragma once

#include <calc/Vector3.h>

class VectorCalculator
{
public:
    static void GetNormalVector2d(
        float fromX, float fromY,
        float toX, float toY,
        float* resultX, float* resultY);
    static void GetNormalVector3d(Vector3& center, Vector3 right, Vector3 front, Vector3& result);
    static bool IsSameDirection(Vector3& base, Vector3 v1, Vector3 v2);
};
