#pragma once

#include <calc/Vector3.h>

struct NewVelocityResult
{
    Vector3 Velocity1;
    Vector3 Velocity2;
};

class Physics
{
public:
    static NewVelocityResult GetNewVelocityAfterCollision(float mass1, Vector3& velocity1, float mass2, Vector3& velocity2);
};
