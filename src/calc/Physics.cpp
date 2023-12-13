#include <calc/Physics.h>

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

    result.Velocity1X = (massDiff * velocity1x + 2.0f * mass2 * velocity2x) / massSum;
    result.Velocity1Y = (massDiff * velocity1y + 2.0f * mass2 * velocity2y) / massSum;

    result.Velocity2X = (-massDiff * velocity2x + 2.0f * mass1 * velocity1x) / massSum;
    result.Velocity2Y = (-massDiff * velocity2y + 2.0f * mass1 * velocity1y) / massSum;

    return result;
}
