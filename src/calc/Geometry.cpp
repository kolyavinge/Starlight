#include "lib/Math.h"
#include "calc/Geometry.h"

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
