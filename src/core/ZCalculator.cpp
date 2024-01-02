#include <calc/Vector3d.h>
#include <calc/PlaneEquation.h>
#include <core/ZCalculator.h>

void ZCalculator::CalculateZIfShipMoving(Ship& ship, Track& track)
{
    if (!ship.IsMoving()) return;
    CalculateZ(ship, track);
}

void ZCalculator::CalculateZ(Ship& ship, Track& track)
{
    ship.CentralLine.Front.Z = 0.0f;
    ship.CentralLine.Rear.Z = 0.0f;
    CalculateForPoint(track, ship.CentralLine.TrackPointIndexFront, ship.CentralLine.Front, ship.CentralLine.NormalFront);
    CalculateForPoint(track, ship.CentralLine.TrackPointIndexRear, ship.CentralLine.Rear, ship.CentralLine.NormalRear);
}

void ZCalculator::CalculateForPoint(Track& track, int& lastNearTrackPointIndex, Vector3d& point, Vector3d& normal)
{
    lastNearTrackPointIndex = track.GetNearestTrackPointIndex(track.InsidePoints, point, lastNearTrackPointIndex);
    PlaneEquation plane(track.Normals[lastNearTrackPointIndex], track.InsidePoints[lastNearTrackPointIndex]);
    point.Z = plane.GetZ(point.X, point.Y);
    normal.Set(track.Normals[lastNearTrackPointIndex]);
}
