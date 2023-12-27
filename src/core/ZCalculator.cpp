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
    int pointIndex = GetNearestInsideTrackPointIndex(track, point);
    PlaneEquation plane(track.Normals[pointIndex], track.InsidePoints[pointIndex]);
    point.Z = plane.GetZ(point.X, point.Y);
    normal.Set(track.Normals[pointIndex]);
}

int ZCalculator::GetNearestInsideTrackPointIndex(Track& track, Vector3d& point)
{
    int result = 0;
    Vector3d v(track.InsidePoints[0]);
    v.Sub(point);
    float minLength = v.GetLengthSquared();
    for (int i = 1; i < track.PointsCount; i++)
    {
        v = track.InsidePoints[i];
        v.Sub(point);
        float length = v.GetLengthSquared();
        if (length < minLength)
        {
            minLength = length;
            result = i;
        }
    }

    return result;
}
