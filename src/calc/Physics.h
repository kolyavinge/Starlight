#pragma once

class NewVelocityResult
{
public:
    float velocity1x;
    float velocity1y;
    float velocity2x;
    float velocity2y;
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
