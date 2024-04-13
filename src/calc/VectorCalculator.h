#pragma once

#include <lib/IArray.h>
#include <calc/Vector3.h>

class VectorCalculator
{
public:
    static void GetNormalVector(Vector3& origin, Vector3 right, Vector3 front, Vector3& result);
    static bool IsSameDirection(Vector3& origin, Vector3 v1, Vector3 v2);
    static Vector3 GetMinVector(IArray<Vector3>& vectors);
    static Vector3 GetMaxVector(IArray<Vector3>& vectors);
    static void SwapXY(IArray<Vector3>& vectors);
    static void SwapXZ(IArray<Vector3>& vectors);
    static void SwapYZ(IArray<Vector3>& vectors);
    static bool IsPointInQuadrant(Vector3& origin, Vector3 axis1, Vector3 axis2, Vector3 point);
};
