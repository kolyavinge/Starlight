#include "lib/Math.h"
#include "calc/Geometry.h"
#include "calc/Vector3d.h"
#include "core/BorderUpdater.h"

void BorderUpdater::Update(Ship& ship)
{
    Vector3d v;

    Geometry::RotatePoint(
        ship.CentralLine.Rear.X, ship.CentralLine.Rear.Y,
        ship.CentralLine.Front.X, ship.CentralLine.Front.Y,
        Math::PiHalf,
        &v.X, &v.Y);

    v.Sub(ship.CentralLine.Front);
    v.SetLength(ShipMeasure::XLengthHalf);

    ship.Border.UpLeft = ship.CentralLine.Front;
    ship.Border.DownLeft = ship.CentralLine.Rear;
    ship.Border.UpRight = ship.CentralLine.Front;
    ship.Border.DownRight = ship.CentralLine.Rear;

    ship.Border.UpLeft.Add(v);
    ship.Border.DownLeft.Add(v);
    ship.Border.UpRight.Sub(v);
    ship.Border.DownRight.Sub(v);
}
