#include <lib/Numeric.h>
#include <calc/Vector3.h>
#include <core/PositionUpdater.h>
#include <core/ShipStateLogic.h>

void ShipStateLogic::ProcessState(Ship& ship, Track& track)
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
        ship.InnactiveIterations--;
        if (ship.InnactiveIterations == 0)
        {
            ship.Reset();
        }
    }
    else if (ship.State == ShipState::Reseted)
    {
        Vector3 frontMiddlePoint(track.OutsidePoints[ship.CentralLine.TrackPointIndexFront]);
        frontMiddlePoint.Sub(track.InsidePoints[ship.CentralLine.TrackPointIndexFront]);
        frontMiddlePoint.Div(2.0f);

        Vector3 frontDirection(track.OutsidePoints[track.GetNextTrackPointIndex(ship.CentralLine.TrackPointIndexFront)]);
        frontDirection.Sub(track.OutsidePoints[ship.CentralLine.TrackPointIndexFront]);

        ship.OrientationByFrontPoint(frontMiddlePoint, frontDirection);
        PositionUpdater positionUpdater;
        positionUpdater.Update(ship, track);

        ship.State = ShipState::ResetInnactive;
    }
    else if (ship.State == ShipState::ResetInnactive)
    {
        ship.InnactiveIterations--;
        if (ship.InnactiveIterations == 0)
        {
            ship.State = ShipState::Active;
        }
    }
}
