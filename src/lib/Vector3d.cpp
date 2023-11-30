#include "lib/Math.h"
#include "lib/HashCode.h"
#include "lib/Vector3d.h"

Vector3d::Vector3d()
{
    Set(0, 0, 0);
}

Vector3d::Vector3d(float x, float y, float z)
{
    Set(x, y, z);
}

bool Vector3d::Equals(Object& a)
{
    Vector3d& v = (Vector3d&)a;
    return (X == v.X) && (Y == v.Y) && (Z == v.Z);
}

int Vector3d::GetHashCode()
{
    HashCode hash;
    hash.Add(X);
    hash.Add(Y);
    hash.Add(Z);

    return hash.GetResult();
}

float Vector3d::GetLength()
{
    return Math::Sqrt(X * X + Y * Y + Z * Z);
}

void Vector3d::Set(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}

Vector3d& Vector3d::Add(Vector3d& v)
{
    X += v.X;
    Y += v.Y;
    Z += v.Z;

    return *this;
}

Vector3d& Vector3d::Sub(Vector3d& v)
{
    X -= v.X;
    Y -= v.Y;
    Z -= v.Z;

    return *this;
}

Vector3d& Vector3d::Mul(float a)
{
    X *= a;
    Y *= a;
    Z *= a;

    return *this;
}

Vector3d& Vector3d::Div(float a)
{
    X /= a;
    Y /= a;
    Z /= a;

    return *this;
}

Vector3d& Vector3d::Normalize()
{
    float length = GetLength();
    if (Math::Abs(length) < 1E-7)
    {
        X = Y = Z = 0;
        return *this;
    }

    return Div(length);
}

float Vector3d::DotProduct(Vector3d& v)
{
    return X * v.X + Y * v.Y + Z * v.Z;
}
