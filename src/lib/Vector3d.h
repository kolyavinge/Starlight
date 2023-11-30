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
    void Set(float x, float y, float z);
    Vector3d& Add(Vector3d& v);
    Vector3d& Sub(Vector3d& v);
    Vector3d& Mul(float a);
    Vector3d& Div(float a);
    Vector3d& Normalize();
    float DotProduct(Vector3d& v);
};
