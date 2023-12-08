#pragma once

#include "lib/Object.h"

class Vector3d : public Object
{
public:
    float X, Y, Z;

    Vector3d();
    Vector3d(float x, float y, float z);

    bool Equals(Object& a) override;
    int GetHashCode() override;
    float GetLength();
    bool IsZero();
    void SetLength(float newLength);
    void Set(float x, float y, float z);
    void Add(Vector3d& v);
    void Sub(Vector3d& v);
    void Mul(float a);
    void Div(float a);
    void Normalize();
    float DotProduct(Vector3d& v);
    void Reflect(Vector3d& normal);
};
