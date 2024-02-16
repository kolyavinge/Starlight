#include <lib/Assert.h>
#include <lib/Numeric.h>
#include <calc/Plane.h>

Plane::Plane(Vector3& normal, Vector3& point)
{
    A = normal.X;
    B = normal.Y;
    C = normal.Z;
    D = -(normal.X * point.X + normal.Y * point.Y + normal.Z * point.Z);
}

float Plane::GetZ(float x, float y)
{
    Assert::False(Numeric::FloatEquals(C, 0.0f));

    float z = -(A * x + B * y + D) / C;

    return z;
}
