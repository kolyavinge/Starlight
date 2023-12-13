#pragma once

#include <calc/Vector3d.h>

class Geometry
{
public:
    static float DegreesToRadians(float degrees);
    static float RadiansToDegrees(float radians);
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
    static Vector3d RotatePoint3d(Vector3d& point, Vector3d& pivot, float radians);

private:
    static const float _piDiv180;
    static const float _180DivPi;
};
