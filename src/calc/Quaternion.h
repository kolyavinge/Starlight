#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>

class Quaternion : public Object
{
    float _w, _x, _y, _z;

public:
    Quaternion();
    Quaternion(float w, float x, float y, float z);
    Quaternion(Vector3& from, Vector3& to);
    Quaternion(float radians, Vector3 pivot);

    float GetMagnitude();
    void GetAngleAndPivot(float& radians, Vector3& pivot);
    void SetIdentity();
    void SetComponents(float w, float x, float y, float z);
    void SetVectors(Vector3& from, Vector3& to);
    void SetAngleAndPivot(float radians, Vector3 pivot);
    void Normalize();
    void Inverse();
    void Mul(Quaternion& q2);
    void RotatePoint(Vector3& point);
};
