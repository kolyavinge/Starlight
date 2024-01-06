#pragma once

#include <lib/Object.h>

class Vector3 : public Object
{
public:
    float X, Y, Z;

    Vector3();
    Vector3(float x, float y, float z);

    bool Equals(Object& a) override;
    int GetHashCode() override;
    float GetLength();
    float GetLengthSquared();
    bool IsZero(float eps = 1e-7f);
    void SetLength(float newLength);
    void Set(Vector3& v);
    void Set(float x, float y, float z);
    void Add(Vector3& v);
    void Sub(Vector3& v);
    void Mul(float a);
    void Div(float a);
    void Normalize();
    float DotProduct(Vector3& v);
    void VectorProduct(Vector3& v);
    void Reflect(Vector3& normal);

private:
    void ErrorIfZeroLength(float length);
};
