#pragma once

#include <lib/List.h>
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
    static Vector3 GetMinVector(List<Vector3>& vectors);
    static Vector3 GetMaxVector(List<Vector3>& vectors);
    static void SwapXY(List<Vector3>& vectors);
    static void SwapXZ(List<Vector3>& vectors);
    static void SwapYZ(List<Vector3>& vectors);
    static bool InQuadrant(Vector3& origin, Vector3 axis1, Vector3 axis2, Vector3 point);
};
