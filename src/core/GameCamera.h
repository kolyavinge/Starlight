#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>
#include <model/Ship.h>

class GameCamera : public Object
{
public:
    Vector3d Position;
    Vector3d LookAt;

    void Update(Ship& ship);
};
