#include <lib/Math.h>
#include <calc/Geometry.h>

float Geometry::NormalizeRadians(float radians)
{
    while (radians > Math::PiDouble)
    {
        radians -= Math::PiDouble;
    }

    return radians;
}

float Geometry::NormalizeDegrees(float degrees)
{
    while (degrees > 360.0f)
    {
        degrees -= 360.0f;
    }

    return degrees;
}

float Geometry::DegreesToRadians(float degrees)
{
    return degrees * _degToRad;
}

float Geometry::RadiansToDegrees(float radians)
{
    return radians * _radToDeg;
}

float Geometry::GetRadiansForDistance(float distance, float radius)
{
    float length = radius * Math::PiDouble;
    float ratio = distance / length;
    float angle = ratio * Math::PiDouble;

    return angle;
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

Vector3 Geometry::RotatePoint3d(Vector3& point, Vector3& pivotAxis, float radians)
{
    // Формула Родрига
    // cos * point + (pivotAxis, point) * (1 - cos) * pivotAxis + sin * [pivotAxis, point]
    // a + b + c

    float sin = Math::Sin(radians);
    float cos = Math::Cos(radians);

    Vector3 a(point);
    a.Mul(cos);

    Vector3 b(pivotAxis);
    b.Mul(pivotAxis.DotProduct(point));
    b.Mul(1.0f - cos);

    Vector3 c(pivotAxis);
    c.VectorProduct(point);
    c.Mul(sin);

    a.Add(b);
    a.Add(c);

    return a;
}

Vector3 Geometry::RotatePoint3d(Vector3 point, Vector3& pivotAxis, Vector3& pivotPoint, float radians)
{
    point.Sub(pivotPoint);
    point = RotatePoint3d(point, pivotAxis, radians);
    point.Add(pivotPoint);

    return point;
}
