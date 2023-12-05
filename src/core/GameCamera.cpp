#include "core/GameCamera.h"

void GameCamera::Update(Ship& ship)
{
    Position = ship.CentralLine.Rear;
    Position.Sub(ship.CentralLine.Front);
    Position.SetLength(1.5f);
    Position.Add(ship.CentralLine.Rear);
    Position.Z += 1.0f;

    LookAt.Set(ship.CentralLine.Front.X, ship.CentralLine.Front.Y, ship.CentralLine.Front.Z);
}
