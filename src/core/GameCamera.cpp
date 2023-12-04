#include "core/GameCamera.h"

void GameCamera::Update(Ship& ship)
{
    Position = ship.RearMiddlePoint;
    Position.Sub(ship.FrontMiddlePoint);
    Position.SetLength(1.5f);
    Position.Add(ship.RearMiddlePoint);
    Position.Z += 1.0f;

    LookAt.Set(ship.FrontMiddlePoint.X, ship.FrontMiddlePoint.Y, ship.FrontMiddlePoint.Z);
}
