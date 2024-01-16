#include <calc/Vector3.h>
#include <calc/Quaternion.h>
#include <model/Border.h>

void Border::GetAngleAndPivot(float& radians, Vector3& pivot)
{
    Vector3 unitX(1.0f, 0.0f, 0.0f);
    Vector3 vx(DownRight);
    vx.Sub(DownLeft);

    Vector3 rotatedY(0.0f, 1.0f, 0.0f);
    Vector3 vy(UpLeft);
    vy.Sub(DownLeft);

    Quaternion result(unitX, vx);
    result.RotatePoint(rotatedY);
    Quaternion qy(rotatedY, vy);
    result.Mul(qy);

    result.GetAngleAndPivot(radians, pivot);
}
