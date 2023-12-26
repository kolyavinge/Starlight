#include <calc/Quaternion.h>
#include <calc/Vector3d.h>
#include <model/RectBorder.h>

void RectBorder::GetRotation(Vector3d& normal, float& radians, Vector3d& pivot)
{
    Vector3d vy(UpLeft);
    vy.Sub(DownLeft);

    Vector3d vz(normal);

    Vector3d y(0, 1, 0);
    Vector3d z(0, 0, 1);

    Quaternion qy(y, vy);
    Quaternion qz(z, vz);

    Quaternion res(qz);
    res.Mul(qy);

    res.GetAngleAndPivot(radians, pivot);
}
