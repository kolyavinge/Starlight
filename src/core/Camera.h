#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/Ship.h>

class Camera : public Object
{
public:
    Vector3 Position;
    Vector3 LookAt;
    float ViewAngle;

    Camera();

    void Update(Ship& ship);
};
