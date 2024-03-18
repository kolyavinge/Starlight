#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>

enum class PowerUpKind { Health, Machinegun };

class PowerUp : public Object
{
public:
    bool IsActive;
    PowerUpKind Kind;
    float Value;
    Vector3 Middle;
    Vector3 From;
    Vector3 To;

    PowerUp();
};
