#include "calc/Physics.h"

NewVelocityResult Physics::GetNewVelocityAfterCollision(
    float mass1,
    float velocity1x,
    float velocity1y,
    float mass2,
    float velocity2x,
    float velocity2y)
{
    NewVelocityResult result;

    float massSum = mass1 + mass2;
    float massDiff = mass1 - mass2;

    result.velocity1x = (massDiff * velocity1x + 2.0f * mass2 * velocity2x) / massSum;
    result.velocity1y = (massDiff * velocity1y + 2.0f * mass2 * velocity2y) / massSum;

    result.velocity2x = (-massDiff * velocity2x + 2.0f * mass1 * velocity1x) / massSum;
    result.velocity2y = (-massDiff * velocity2y + 2.0f * mass1 * velocity1y) / massSum;

    return result;
}
