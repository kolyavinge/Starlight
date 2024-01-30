#include <core/Camera.h>

Camera::Camera()
{
    ViewAngle = 0.0f;
}

void Camera::Update(Ship& ship)
{
    Position = ship.CentralLine.Rear;
    Position.Sub(ship.CentralLine.Front);
    Position.SetLength(2.0f);
    Position.Add(ship.CentralLine.Rear);
    Position.Z += 1.5f;

    LookAt.Set(ship.CentralLine.Front);

    ViewAngle = 60.0f + 2.0f * ship.VelocityValue;
}
