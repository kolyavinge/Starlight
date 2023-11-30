#pragma once

class Geometry
{
public:
    static void RotatePoint(
        float pointX,
        float pointY,
        float pivotX,
        float pivotY,
        float radians,
        float* resultX,
        float* resultY);
};
