#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>

class PlaneEquation : public Object
{
public:
    float A, B, C, D;

    PlaneEquation(Vector3d& normal, Vector3d& point);

    float GetZ(float x, float y);
};
