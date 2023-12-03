#include "core/GameCamera.h"

void GameCamera::Update(Ship& ship)
{
    Position.Set(ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y - 2.0f, ship.RearMiddlePoint.Z + 2.0f);

    LookAt.Set(ship.FrontMiddlePoint.X, ship.FrontMiddlePoint.Y, ship.FrontMiddlePoint.Z);
}
