#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>

class Bullet : public Object
{
public:
    bool IsActive;
    Vector3 Position;
    Vector3 PrevPosition;
    Vector3 Direction;
    float MovingDistance;
    float TotalDistance;
    float DamageValue;

    Bullet();

    void Init();
};
