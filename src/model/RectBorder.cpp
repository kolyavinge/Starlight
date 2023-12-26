#include <calc/Vector3d.h>
#include <calc/Quaternion.h>
#include <model/RectBorder.h>

void RectBorder::GetAngleAndPivot(float& radians, Vector3d& pivot)
{
    Vector3d unitX(1.0f, 0.0f, 0.0f);
    Vector3d vx(DownRight);
    vx.Sub(DownLeft);

    Vector3d rotatedY(0.0f, 1.0f, 0.0f);
    Vector3d vy(UpLeft);
    vy.Sub(DownLeft);

    Quaternion result(unitX, vx);
    result.RotatePoint(rotatedY);
    Quaternion qy(rotatedY, vy);
    result.Mul(qy);

    result.GetAngleAndPivot(radians, pivot);
}
