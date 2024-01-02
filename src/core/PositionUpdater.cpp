#include <calc/Vector3d.h>
#include <calc/PlaneEquation.h>
#include <core/PositionUpdater.h>

void PositionUpdater::UpdateIfShipMoving(Ship& ship, Track& track)
{
    if (!ship.IsMoving()) return;
    Update(ship, track);
}

void PositionUpdater::Update(Ship& ship, Track& track)
{
    UpdateTrackPointIndexes(ship, track);
    UpdateZ(ship, track);
}

void PositionUpdater::UpdateTrackPointIndexes(Ship& ship, Track& track)
{
    ship.CentralLine.TrackPointIndexFront = track.GetTrackPointIndexFor(track.InsidePoints, ship.CentralLine.Front, ship.CentralLine.TrackPointIndexFront);
    ship.CentralLine.TrackPointIndexRear = track.GetTrackPointIndexFor(track.InsidePoints, ship.CentralLine.Rear, ship.CentralLine.TrackPointIndexRear);
}

void PositionUpdater::UpdateZ(Ship& ship, Track& track)
{
    ship.CentralLine.Front.Z = 0.0f;
    ship.CentralLine.Rear.Z = 0.0f;
    CalculateZForPoint(track, ship.CentralLine.TrackPointIndexFront, ship.CentralLine.Front, ship.CentralLine.NormalFront);
    CalculateZForPoint(track, ship.CentralLine.TrackPointIndexRear, ship.CentralLine.Rear, ship.CentralLine.NormalRear);
}

void PositionUpdater::CalculateZForPoint(Track& track, int trackPointIndex, Vector3d& point, Vector3d& normal)
{
    PlaneEquation plane(track.Normals[trackPointIndex], track.InsidePoints[trackPointIndex]);
    point.Z = plane.GetZ(point.X, point.Y);
    normal.Set(track.Normals[trackPointIndex]);
}
