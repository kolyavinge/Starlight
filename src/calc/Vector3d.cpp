#include "lib/Math.h"
#include "lib/Numeric.h"
#include "lib/HashCode.h"
#include "calc/Vector3d.h"

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

void Vector3d::Add(Vector3d& v)
{
    X += v.X;
    Y += v.Y;
    Z += v.Z;
}

void Vector3d::Sub(Vector3d& v)
{
    X -= v.X;
    Y -= v.Y;
    Z -= v.Z;
}

void Vector3d::Mul(float a)
{
    X *= a;
    Y *= a;
    Z *= a;
}

void Vector3d::Div(float a)
{
    X /= a;
    Y /= a;
    Z /= a;
}

void Vector3d::Normalize()
{
    float length = GetLength();
    if (Numeric::FloatEquals(length, 0.0f))
    {
        X = Y = Z = 0;
    }

    Div(length);
}

float Vector3d::DotProduct(Vector3d& v)
{
    return X * v.X + Y * v.Y + Z * v.Z;
}

void Vector3d::Reflect(Vector3d& normal)
{
    // vector - 2.0f * (vector * normal) * normal
    float product = 2.0f * (X * normal.X + Y * normal.Y + Z * normal.Z);
    X -= product * normal.X;
    Y -= product * normal.Y;
    Z -= product * normal.Z;
}
