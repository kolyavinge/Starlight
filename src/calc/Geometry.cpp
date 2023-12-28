#include <lib/Math.h>
#include <calc/Geometry.h>

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

Vector3d Geometry::RotatePoint3d(Vector3d& point, Vector3d& pivotAxis, float radians)
{
    // Формула Родрига
    // cos * point + (pivotAxis, point) * (1 - cos) * pivotAxis + sin * [pivotAxis, point]
    // a + b + c

    float sin = Math::Sin(radians);
    float cos = Math::Cos(radians);

    Vector3d a(point);
    a.Mul(cos);

    Vector3d b(pivotAxis);
    b.Mul(pivotAxis.DotProduct(point));
    b.Mul(1.0f - cos);

    Vector3d c(pivotAxis);
    c.VectorProduct(point);
    c.Mul(sin);

    a.Add(b);
    a.Add(c);

    return a;
}

Vector3d Geometry::RotatePoint3d(Vector3d point, Vector3d& pivotAxis, Vector3d& pivotPoint, float radians)
{
    point.Sub(pivotPoint);
    point = RotatePoint3d(point, pivotAxis, radians);
    point.Add(pivotPoint);

    return point;
}
