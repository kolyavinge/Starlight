#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <core/ShipStateLogic.h>

void ShipStateLogic::ProcessState(Ship& ship, IArray<Ship*>& allShips, Track& track)
{
    if (ship.State == ShipState::Active &&
        Numeric::FloatEquals(ship.Health, 0.0f))
    {
        ship.Explode();
    }
    else if (ship.State == ShipState::Exploded)
    {
        ship.State = ShipState::Destroyed;
    }
    else if (ship.State == ShipState::Destroyed)
    {
        ship.DelayIterations--;
        if (ship.DelayIterations == 0)
        {
            ship.Reset();
        }
    }
    else if (ship.State == ShipState::Reseted)
    {
        SetShipAtMiddle(ship, track);
        ship.State = ShipState::Prepared;
    }
    else if (ship.State == ShipState::Prepared)
    {
        ship.DelayIterations--;
        if (ship.DelayIterations == 0)
        {
            if (_shipCollisionDetector.DetectCollisions(ship, allShips))
            {
                ship.DelayIterations = 10;
            }
            else
            {
                ship.State = ShipState::Active;
            }
        }
    }
}

void ShipStateLogic::SetShipAtMiddle(Ship& ship, Track& track)
{
    const int trackPoint = ship.CentralLine.TrackPointIndexFront;

    Vector3 middlePoint(track.OutsidePoints[trackPoint]);
    middlePoint.Sub(track.InsidePoints[trackPoint]);
    middlePoint.Div(2.0f);
    middlePoint.Add(track.InsidePoints[trackPoint]);

    Vector3 frontDirection(track.OutsidePoints[track.GetNextTrackPointIndex(trackPoint)]);
    frontDirection.Sub(track.OutsidePoints[trackPoint]);

    ship.OrientationByFrontPoint(middlePoint, frontDirection);
}

ShipStateLogic* ShipStateLogicResolvingFactory::Make(Resolver&)
{
    return new ShipStateLogic();
}
