#include <core/GameCamera.h>

void GameCamera::Update(Ship& ship)
{
    Position = ship.CentralLine.Rear;
    Position.Sub(ship.CentralLine.Front);
    Position.SetLength(1.8f + 0.25f * ship.VelocityValue);
    Position.Add(ship.CentralLine.Rear);
    Position.Z += 2.5f;

    LookAt.Set(ship.CentralLine.Front);
}
