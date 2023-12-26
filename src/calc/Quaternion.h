#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>

class Quaternion : public Object
{
    float _w, _x, _y, _z;

public:
    Quaternion();
    Quaternion(float w, float x, float y, float z);
    Quaternion(Vector3d& from, Vector3d& to);
    Quaternion(float radians, Vector3d pivot);

    float GetMagnitude();
    void GetAngleAndPivot(float& radians, Vector3d& pivot);
    void SetIdentity();
    void SetComponents(float w, float x, float y, float z);
    void SetVectors(Vector3d& from, Vector3d& to);
    void SetAngleAndPivot(float radians, Vector3d pivot);
    void Normalize();
    void Inverse();
    void Mul(Quaternion& q2);
    void RotatePoint(Vector3d& point);
};
