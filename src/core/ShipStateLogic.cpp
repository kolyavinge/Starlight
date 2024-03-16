#include <lib/Numeric.h>
#include <calc/Vector3.h>
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
        const int trackPoint = ship.CentralLine.TrackPointIndexFront;
        Vector3 frontMiddlePoint(track.OutsidePoints[trackPoint]);
        frontMiddlePoint.Sub(track.InsidePoints[trackPoint]);
        frontMiddlePoint.Div(2.0f);
        frontMiddlePoint.Add(track.InsidePoints[trackPoint]);
        Vector3 frontDirection(track.OutsidePoints[track.GetNextTrackPointIndex(trackPoint)]);
        frontDirection.Sub(track.OutsidePoints[trackPoint]);
        ship.OrientationByFrontPoint(frontMiddlePoint, frontDirection);
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
