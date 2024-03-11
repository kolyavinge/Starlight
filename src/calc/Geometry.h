#pragma once

#include <lib/Math.h>
#include <calc/Vector3.h>

class Geometry
{
public:
    static float NormalizeRadians(float radians);
    static float NormalizeDegrees(float degrees);
    static float DegreesToRadians(float degrees);
    static float RadiansToDegrees(float radians);
    static float GetRadiansForDistance(float distance, float radius);
    static float GetFunctionValueByPoints(
        float x0, float x1,
        float y0, float y1,
        float x);
    static void RotatePoint2d(
        float pointX,
        float pointY,
        float pivotX,
        float pivotY,
        float radians,
        float* resultX,
        float* resultY);
    static Vector3 RotatePoint3d(Vector3& point, Vector3& pivotAxis, float radians);
    static Vector3 RotatePoint3d(Vector3 point, Vector3& pivotAxis, Vector3& pivotPoint, float radians);
    static void RotateCoordinateSystem3d(Vector3& axis1From, Vector3& axis1To, Vector3& axis2From, Vector3& axis2To, float& radians, Vector3& pivot);

private:
    inline static const float _degToRad = Math::Pi / 180.0f;
    inline static const float _radToDeg = 180.0f / Math::Pi;
};
