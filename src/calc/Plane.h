#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>

class Plane : public Object
{
public:
    float A, B, C, D;

    Plane(Vector3& normal, Vector3& point);

    float GetZ(float x, float y);
};
