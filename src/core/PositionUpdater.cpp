#include <calc/Vector3d.h>
#include <calc/PlaneEquation.h>
#include <core/PositionUpdater.h>

void PositionUpdater::UpdateIfShipMoving(Ship& ship, Track& track)
{
    if (ship.IsMoving())
    {
        Update(ship, track);
    }
}

void PositionUpdater::Update(Ship& ship, Track& track)
{
    UpdateTrackPointIndexes(ship, track);
    UpdateZ(ship, track);
    UpdateNormals(ship, track);
}

void PositionUpdater::UpdateTrackPointIndexes(Ship& ship, Track& track)
{
    ship.CentralLine.TrackPointIndexFront = track.GetTrackPointIndexFor(ship.CentralLine.Front, ship.CentralLine.TrackPointIndexFront);
    ship.CentralLine.TrackPointIndexRear = track.GetTrackPointIndexFor(ship.CentralLine.Rear, ship.CentralLine.TrackPointIndexRear);
}

void PositionUpdater::UpdateZ(Ship& ship, Track& track)
{
    CalculateZForPoint(track, ship.CentralLine.TrackPointIndexFront, ship.CentralLine.Front);
    CalculateZForPoint(track, ship.CentralLine.TrackPointIndexRear, ship.CentralLine.Rear);
}

void PositionUpdater::UpdateNormals(Ship& ship, Track& track)
{
    ship.CentralLine.NormalFront.Set(track.Normals[ship.CentralLine.TrackPointIndexFront]);
    ship.CentralLine.NormalRear.Set(track.Normals[ship.CentralLine.TrackPointIndexRear]);
}

void PositionUpdater::CalculateZForPoint(Track& track, int trackPointIndex, Vector3d& point)
{
    PlaneEquation plane(track.Normals[trackPointIndex], track.InsidePoints[trackPointIndex]);
    point.Z = plane.GetZ(point.X, point.Y);
}
