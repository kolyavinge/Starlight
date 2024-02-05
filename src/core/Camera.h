#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <model/Ship.h>

class Camera : public Object
{
public:
    Vector3 Position;
    Vector3 LookAt;
    float ViewAngleDegrees;

    Camera();

    void SetFrontView(Ship& ship);
    void SetRearView(Ship& ship);
    void RotateBy(float radians);

private:
    void SetView(Vector3& front, Vector3& rear, float velocityValue);
};
