#include <calc/PlaneEquation.h>

PlaneEquation::PlaneEquation(Vector3d& normal, Vector3d& point)
{
    A = normal.X;
    B = normal.Y;
    C = normal.Z;
    D = -(normal.X * point.X + normal.Y * point.Y + normal.Z * point.Z);
}

float PlaneEquation::GetZ(float x, float y)
{
    float z = -(A * x + B * y + D) / C;
    return z;
}
