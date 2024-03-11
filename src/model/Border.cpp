#include <calc/Vector3.h>
#include <calc/VectorCalculator.h>
#include <calc/Geometry.h>
#include <model/Border.h>

void Border::Init()
{
    UpLeft.Set(0.0f, 0.0f, 0.0f);
    UpRight.Set(0.0f, 0.0f, 0.0f);
    DownLeft.Set(0.0f, 0.0f, 0.0f);
    DownRight.Set(0.0f, 0.0f, 0.0f);
}

void Border::GetAngleAndPivot(float& radians, Vector3& pivot)
{
    Vector3 unitX(1.0f, 0.0f, 0.0f);
    Vector3 vx(DownRight);
    vx.Sub(DownLeft);

    Vector3 unitY(0.0f, 1.0f, 0.0f);
    Vector3 vy(UpLeft);
    vy.Sub(DownLeft);

    Geometry::RotateCoordinateSystem3d(unitX, vx, unitY, vy, radians, pivot);
}

bool Border::Contains(Vector3& point)
{
    return
        VectorCalculator::IsPointInQuadrant(UpLeft, UpRight, DownLeft, point) &&
        VectorCalculator::IsPointInQuadrant(UpLeft, DownLeft, UpRight, point) &&
        VectorCalculator::IsPointInQuadrant(DownRight, DownLeft, UpRight, point) &&
        VectorCalculator::IsPointInQuadrant(DownRight, UpRight, DownLeft, point);
}
