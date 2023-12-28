#pragma once

#include <lib/Math.h>
#include <calc/Vector3d.h>

class Geometry
{
public:
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
    static Vector3d RotatePoint3d(Vector3d& point, Vector3d& pivotAxis, float radians);
    static Vector3d RotatePoint3d(Vector3d point, Vector3d& pivotAxis, Vector3d& pivotPoint, float radians);

private:
    inline static const float _degToRad = Math::Pi / 180.0f;
    inline static const float _radToDeg = 180.0f / Math::Pi;
};
