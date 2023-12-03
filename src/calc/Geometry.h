#pragma once

class Geometry
{
public:
    static float DegreesToRadians(float degrees);
    static float RadiansToDegrees(float radians);
    static void RotatePoint(
        float pointX,
        float pointY,
        float pivotX,
        float pivotY,
        float radians,
        float* resultX,
        float* resultY);

private:
    static const float _piDiv180;
    static const float _180DivPi;
};
