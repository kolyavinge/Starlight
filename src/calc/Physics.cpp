#include <calc/Physics.h>

NewVelocityResult Physics::GetNewVelocityAfterCollision(float mass1, Vector3& velocity1, float mass2, Vector3& velocity2)
{
    NewVelocityResult result;

    float massSum = mass1 + mass2;
    float massDiff = mass1 - mass2;

    // Velocity1 = (massDiff * velocity1 + 2.0f * mass2 * velocity2) / massSum;

    Vector3 tmp(velocity2);
    tmp.Mul(2.0f * mass2);

    result.Velocity1.Set(velocity1);
    result.Velocity1.Mul(massDiff);
    result.Velocity1.Add(tmp);
    result.Velocity1.Div(massSum);

    // Velocity2 = (-massDiff * velocity2 + 2.0f * mass1 * velocity1) / massSum

    tmp.Set(velocity1);
    tmp.Mul(2.0f * mass1);

    result.Velocity2.Set(velocity2);
    result.Velocity2.Mul(-massDiff);
    result.Velocity2.Add(tmp);
    result.Velocity2.Div(massSum);

    return result;
}
