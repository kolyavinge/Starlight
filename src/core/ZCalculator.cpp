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
    CalculateForPoint(track, ship.CentralLine.Front, ship.CentralLine.NormalFront);
    CalculateForPoint(track, ship.CentralLine.Rear, ship.CentralLine.NormalRear);
}

void ZCalculator::CalculateForPoint(Track& track, Vector3d& point, Vector3d& normal)
{
    int pointIndex = track.GetNearestTrackPointIndex(track.InsidePoints, point);
    PlaneEquation plane(track.Normals[pointIndex], track.InsidePoints[pointIndex]);
    point.Z = plane.GetZ(point.X, point.Y);
    normal.Set(track.Normals[pointIndex]);
}
