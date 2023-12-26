#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>

class Quaternion : public Object
{
    float _w, _x, _y, _z;

public:
    Quaternion();
    Quaternion(Vector3d& from, Vector3d& to);

    float GetMagnitude();
    void GetAngleAndPivot(float& radians, Vector3d& pivot);
    void SetUnit();
    void SetComponents(float w, float x, float y, float z);
    void SetVectors(Vector3d& from, Vector3d& to);
    void SetAngleAndPivot(float radians, Vector3d pivot);
    void Normalize();
    void Mul(Quaternion& q2);
};
