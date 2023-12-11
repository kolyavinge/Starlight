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

float Geometry::GetFunctionValueByPoints(
    float x0, float x1,
    float y0, float y1,
    float x)
{
    float y = (y1 - y0) / (x1 - x0) * (x - x0) + y0;
    return y;
}

void Geometry::RotatePoint2d(
    float pointX,
    float pointY,
    float pivotX,
    float pivotY,
    float radians,
    float* resultX,
    float* resultY)
{
    float cos = Math::Cos(radians);
    float sin = Math::Sin(radians);

    *resultX = cos * (pointX - pivotX) - sin * (pointY - pivotY) + pivotX;
    *resultY = sin * (pointX - pivotX) + cos * (pointY - pivotY) + pivotY;
}

Vector3d Geometry::RotatePoint3d(Vector3d& point, Vector3d& pivot, float radians)
{
    // Формула Родрига
    // cos * point + (pivot, point) * (1 - cos) * pivot + sin * [pivot, point]
    // a + b + c

    float sin = Math::Sin(radians);
    float cos = Math::Cos(radians);

    Vector3d a(point);
    a.Mul(cos);

    Vector3d b(pivot);
    b.Mul(pivot.DotProduct(point));
    b.Mul(1.0f - cos);

    Vector3d c(pivot);
    c.VectorProduct(point);
    c.Mul(sin);

    a.Add(b);
    a.Add(c);

    return a;
}
