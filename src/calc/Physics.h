#pragma once

struct NewVelocityResult
{
    float Velocity1X;
    float Velocity1Y;
    float Velocity2X;
    float Velocity2Y;
};

class Physics
{
public:
    static NewVelocityResult GetNewVelocityAfterCollision(
        float mass1,
        float velocity1x,
        float velocity1y,
        float mass2,
        float velocity2x,
        float velocity2y);
};
