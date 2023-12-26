#include <lib/Math.h>
#include <lib/Numeric.h>
#include <calc/Vector3d.h>
#include <calc/Quaternion.h>

Quaternion::Quaternion()
{
    SetUnit();
}

Quaternion::Quaternion(Vector3d& from, Vector3d& to)
{
    SetVectors(from, to);
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

void Quaternion::SetUnit()
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
    float dotProduct = from.DotProduct(to);
    if (Numeric::FloatEquals(dotProduct, 0.0f))
    {
        SetUnit();
        return;
    }
    float cosAlpha = dotProduct / (from.GetLength() * to.GetLength());
    if (cosAlpha < -1.0f + 0.0001f)
    {
        Vector3d pivot(1.0f, 0.0f, 0.0f);
        pivot.VectorProduct(from);
        if (pivot.IsZero())
        {
            pivot.Set(0.0f, 0.0f, 1.0f);
            pivot.VectorProduct(from);
        }
        SetAngleAndPivot(Math::Pi, pivot);
    }
    else
    {
        float alpha = Math::ArcCos(cosAlpha);
        Vector3d pivot(from);
        pivot.VectorProduct(to);
        if (!pivot.IsZero())
        {
            SetAngleAndPivot(alpha, pivot);
        }
        else
        {
            SetUnit();
        }
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
    _w /= mg;
    _x /= mg;
    _y /= mg;
    _z /= mg;
}

void Quaternion::Mul(Quaternion& q2)
{
    Quaternion& q1 = *this;
    float x = (q2._w * q1._x) + (q2._x * q1._w) + (q2._y * q1._z) - (q2._z * q1._y);
    float y = (q2._w * q1._y) - (q2._x * q1._z) + (q2._y * q1._w) + (q2._z * q1._x);
    float z = (q2._w * q1._z) + (q2._x * q1._y) - (q2._y * q1._x) + (q2._z * q1._w);
    float w = (q2._w * q1._w) - (q2._x * q1._x) - (q2._y * q1._y) - (q2._z * q1._z);
    SetComponents(w, x, y, z);
}
