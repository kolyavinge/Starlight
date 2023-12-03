#include "lib/Math.h"
#include "calc/Geometry.h"

const float Geometry::_piDiv180 = Math::Pi / 180.0f;
const float Geometry::_180DivPi = 180.0f / Math::Pi;

float Geometry::DegreesToRadians(float degrees)
{
    return degrees * _piDiv180;
}

float Geometry::RadiansToDegrees(float radians)
{
    return radians * _180DivPi;
}

void Geometry::RotatePoint(
    float pointX,
    float pointY,
    float pivotX,
    float pivotY,
    float radians,
    float* resultX,
    float* resultY)
{
    float cosAlpha = Math::Cos(radians);
    float sinAlpha = Math::Sin(radians);

    *resultX = cosAlpha * (pointX - pivotX) - sinAlpha * (pointY - pivotY) + pivotX;
    *resultY = sinAlpha * (pointX - pivotX) + cosAlpha * (pointY - pivotY) + pivotY;
}
