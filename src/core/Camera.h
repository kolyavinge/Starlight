#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <calc/Matrix4.h>
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
    void GetViewMatrix(Matrix4& viewMatrix);

private:
    void SetView(Vector3& front, Vector3& rear, float velocityValue);
};

class CameraResolvingFactory : public ResolvingFactory<Camera>
{
public:
    Camera* Make(Resolver& resolver) override;
};
