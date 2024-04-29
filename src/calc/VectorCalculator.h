#pragma once

#include <lib/Collection.h>
#include <calc/Vector3.h>

class VectorCalculator
{
public:
    static void GetNormalVector(Vector3& origin, Vector3 right, Vector3 front, Vector3& result);
    static bool IsSameDirection(Vector3& origin, Vector3 v1, Vector3 v2);
    static Vector3 GetMinVector(Collection<Vector3>& vectors);
    static Vector3 GetMaxVector(Collection<Vector3>& vectors);
    static void SwapXY(Collection<Vector3>& vectors);
    static void SwapXZ(Collection<Vector3>& vectors);
    static void SwapYZ(Collection<Vector3>& vectors);
    static bool IsPointInQuadrant(Vector3& origin, Vector3 axis1, Vector3 axis2, Vector3 point);
};
