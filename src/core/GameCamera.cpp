#include <core/GameCamera.h>

void GameCamera::Update(Ship& ship)
{
    Position = ship.CentralLine.Rear;
    Position.Sub(ship.CentralLine.Front);
    Position.SetLength(3.0f);
    Position.Add(ship.CentralLine.Rear);
    Position.Z += 3.0f;

    LookAt.Set(ship.CentralLine.Front);
}
