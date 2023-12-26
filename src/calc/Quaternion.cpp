#include <lib/Exceptions.h>
#include <lib/Math.h>
#include <lib/Numeric.h>
#include <calc/Vector3d.h>
#include <calc/Quaternion.h>

Quaternion::Quaternion()
{
    SetIdentity();
}

Quaternion::Quaternion(float w, float x, float y, float z)
{
    SetComponents(w, x, y, z);
}

Quaternion::Quaternion(Vector3d& from, Vector3d& to)
{
    SetVectors(from, to);
}

Quaternion::Quaternion(float radians, Vector3d pivot)
{
    SetAngleAndPivot(radians, pivot);
}

float Quaternion::GetMagnitude()
{
    return Math::Sqrt(_w * _w + _x * _x + _y * _y + _z * _z);
}

void Quaternion::GetAngleAndPivot(float& radians, Vector3d& pivot)
{
    float alphaHalf = Math::ArcCos(_w);
    radians = 2.0f * alphaHalf;
    float sinHalf = Math::Sin(alphaHalf);
    pivot.Set(_x, _y, _z);
    pivot.Div(sinHalf);
}

void Quaternion::SetIdentity()
{
    SetComponents(1.0f, 0.0f, 0.0f, 0.0f);
}

void Quaternion::SetComponents(float w, float x, float y, float z)
{
    _w = w;
    _x = x;
    _y = y;
    _z = z;
}

void Quaternion::SetVectors(Vector3d& from, Vector3d& to)
{
    if (from.IsZero() || to.IsZero())
    {
        SetIdentity();
        return;
    }
    float dotProduct = from.DotProduct(to);
    float cosAlpha = dotProduct / (from.GetLength() * to.GetLength()); // normalized vectors
    if (cosAlpha > 1.0f) // float issues
    {
        cosAlpha = 1.0f;
    }
    else if (cosAlpha < -1.0f)
    {
        cosAlpha = -1.0f;
    }
    float alpha = Math::ArcCos(cosAlpha);
    Vector3d pivot(from);
    pivot.VectorProduct(to);
    if (!pivot.IsZero())
    {
        SetAngleAndPivot(alpha, pivot);
    }
    else
    {
        SetIdentity();
    }
}

void Quaternion::SetAngleAndPivot(float radians, Vector3d pivot)
{
    float sinHalf = Math::Sin(radians / 2.0f);
    float cosHalf = Math::Cos(radians / 2.0f);
    pivot.Normalize();
    pivot.Mul(sinHalf);
    SetComponents(cosHalf, pivot.X, pivot.Y, pivot.Z);
}

void Quaternion::Normalize()
{
    float mg = GetMagnitude();
    if (Numeric::FloatEquals(mg, 0.0f)) throw ObjectStateException();
    _w /= mg;
    _x /= mg;
    _y /= mg;
    _z /= mg;
}

void Quaternion::Inverse()
{
    _x = -_x;
    _y = -_y;
    _z = -_z;
}

void Quaternion::Mul(Quaternion& q2)
{
    Quaternion& q1 = *this;
    float w = (q2._w * q1._w) - (q2._x * q1._x) - (q2._y * q1._y) - (q2._z * q1._z);
    float x = (q2._w * q1._x) + (q2._x * q1._w) + (q2._y * q1._z) - (q2._z * q1._y);
    float y = (q2._w * q1._y) - (q2._x * q1._z) + (q2._y * q1._w) + (q2._z * q1._x);
    float z = (q2._w * q1._z) + (q2._x * q1._y) - (q2._y * q1._x) + (q2._z * q1._w);
    SetComponents(w, x, y, z);
}

void Quaternion::RotatePoint(Vector3d& point)
{
    Quaternion p(0.0f, point.X, point.Y, point.Z);

    Quaternion res(*this);
    res.Inverse();
    res.Mul(p);
    res.Mul(*this);

    point.X = res._x;
    point.Y = res._y;
    point.Z = res._z;
}
