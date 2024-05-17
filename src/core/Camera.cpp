#include <calc/Geometry.h>
#include <core/Constants.h>
#include <core/Camera.h>

Camera::Camera()
{
    ViewAngleDegrees = 0.0f;
}

void Camera::SetFrontView(Ship& ship)
{
    SetView(ship.CentralLine.Front, ship.CentralLine.Rear, ship.VelocityValue);
}

void Camera::SetRearView(Ship& ship)
{
    SetView(ship.CentralLine.Rear, ship.CentralLine.Front, ship.VelocityValue);
}

void Camera::RotateBy(float radians)
{
    Position = Geometry::RotatePoint3d(Position, Constants::UpAxis, LookAt, radians);
}

void Camera::GetViewMatrix(Matrix4& viewMatrix)
{
    viewMatrix.LookAt(Position, LookAt, Constants::UpAxis);
}

void Camera::SetView(Vector3& front, Vector3& rear, float velocityValue)
{
    Position = rear;
    Position.Sub(front);
    Position.SetLength(2.0f);
    Position.Add(rear);
    Position.Z += 1.5f;

    LookAt.Set(front);

    ViewAngleDegrees = 60.0f + 1.5f * velocityValue;
}

Camera* CameraResolvingFactory::Make(Resolver&)
{
    return new Camera();
}
