#include <lib/Exceptions.h>
#include <lib/Math.h>
#include <lib/Numeric.h>
#include <lib/HashCode.h>
#include <calc/Vector3.h>

Vector3::Vector3()
{
    Set(0.0f, 0.0f, 0.0f);
}

Vector3::Vector3(float x, float y, float z)
{
    Set(x, y, z);
}

bool Vector3::Equals(Object& a)
{
    Vector3& v = (Vector3&)a;
    return Numeric::FloatEquals(X, v.X) && Numeric::FloatEquals(Y, v.Y) && Numeric::FloatEquals(Z, v.Z);
}

int Vector3::GetHashCode()
{
    HashCode hash;
    hash.Add(X);
    hash.Add(Y);
    hash.Add(Z);

    return hash.GetResult();
}

float Vector3::GetLength()
{
    return Math::Sqrt(X * X + Y * Y + Z * Z);
}

float Vector3::GetLengthSquared()
{
    return X * X + Y * Y + Z * Z;
}

bool Vector3::IsZero(float eps)
{
    return
        Numeric::FloatEquals(X, 0.0f, eps) &&
        Numeric::FloatEquals(Y, 0.0f, eps) &&
        Numeric::FloatEquals(Z, 0.0f, eps);
}

void Vector3::SetLength(float newLength)
{
    if (newLength < 0.0f) throw ArgumentException();
    float length = GetLength();
    ErrorIfZeroLength(length);
    Mul(newLength / length);
}

void Vector3::Set(Vector3& v)
{
    Set(v.X, v.Y, v.Z);
}

void Vector3::Set(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}

void Vector3::Add(Vector3& v)
{
    X += v.X;
    Y += v.Y;
    Z += v.Z;
}

void Vector3::Sub(Vector3& v)
{
    X -= v.X;
    Y -= v.Y;
    Z -= v.Z;
}

void Vector3::Mul(float a)
{
    X *= a;
    Y *= a;
    Z *= a;
}

void Vector3::Div(float a)
{
    X /= a;
    Y /= a;
    Z /= a;
}

void Vector3::Normalize()
{
    float length = GetLength();
    ErrorIfZeroLength(length);
    Div(length);
}

float Vector3::DotProduct(Vector3& v)
{
    return X * v.X + Y * v.Y + Z * v.Z;
}

void Vector3::VectorProduct(Vector3& v)
{
    float x = Y * v.Z - Z * v.Y;
    float y = Z * v.X - X * v.Z;
    float z = X * v.Y - Y * v.X;
    X = x;
    Y = y;
    Z = z;
}

void Vector3::Reflect(Vector3& normal)
{
    // vector - 2.0f * (vector * normal) * normal
    float product = 2.0f * (X * normal.X + Y * normal.Y + Z * normal.Z);
    X -= product * normal.X;
    Y -= product * normal.Y;
    Z -= product * normal.Z;
}

void Vector3::ErrorIfZeroLength(float length)
{
    if (Numeric::FloatEquals(length, 0.0f))
    {
        throw ObjectStateException();
    }
}
