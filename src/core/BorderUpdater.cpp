#include "calc/Vector3d.h"
#include "core/BorderUpdater.h"

void BorderUpdater::Update(Ship& ship)
{
    Vector3d front(ship.CentralLine.Front);
    front.Sub(ship.CentralLine.Rear);
    front.VectorProduct(ship.CentralLine.NormalFront);
    front.SetLength(ShipMeasure::XLengthHalf);

    Vector3d rear(ship.CentralLine.Front);
    rear.Sub(ship.CentralLine.Rear);
    rear.VectorProduct(ship.CentralLine.NormalRear);
    rear.SetLength(ShipMeasure::XLengthHalf);

    ship.Border.UpLeft = ship.CentralLine.Front;
    ship.Border.DownLeft = ship.CentralLine.Rear;
    ship.Border.UpRight = ship.CentralLine.Front;
    ship.Border.DownRight = ship.CentralLine.Rear;

    ship.Border.UpLeft.Sub(front);
    ship.Border.UpRight.Add(front);
    ship.Border.DownLeft.Sub(rear);
    ship.Border.DownRight.Add(rear);
}
