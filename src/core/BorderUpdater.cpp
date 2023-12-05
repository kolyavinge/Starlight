#include "lib/Math.h"
#include "calc/Geometry.h"
#include "calc/Vector3d.h"
#include "core/BorderUpdater.h"

void BorderUpdater::Update(Ship& ship)
{
    Vector3d v;

    Geometry::RotatePoint(
        ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y,
        ship.FrontMiddlePoint.X, ship.FrontMiddlePoint.Y,
        Math::PiHalf,
        &v.X, &v.Y);

    v.Sub(ship.FrontMiddlePoint);
    v.SetLength(Ship::XLengthHalf);

    ship.Border.UpLeft = ship.FrontMiddlePoint;
    ship.Border.DownLeft = ship.RearMiddlePoint;
    ship.Border.UpRight = ship.FrontMiddlePoint;
    ship.Border.DownRight = ship.RearMiddlePoint;

    ship.Border.UpLeft.Add(v);
    ship.Border.DownLeft.Add(v);
    ship.Border.UpRight.Sub(v);
    ship.Border.DownRight.Sub(v);
}
