#include <lib/Array.h>
#include <core/ZCalculator.h>

void ZCalculator::CalculateZ(Ship& ship, Track& track)
{
    ship.CentralLine.Front.Z = 0.0f;
    ship.CentralLine.Rear.Z = 0.0f;
    CalculateForPoint(ship.CentralLine.Front, ship.CentralLine.NormalFront, track);
    CalculateForPoint(ship.CentralLine.Rear, ship.CentralLine.NormalRear, track);
}

void ZCalculator::CalculateForPoint(Vector3d& point, Vector3d& normal, Track& track)
{
    int pointIndex = GetNearestTrackPointIndex(point, track);
    Array<Vector3d, TrackMaxMiddlePoints>& middlePoints = track.MiddlePoints[pointIndex];
    point.Z = GetNearestMiddlePointZ(middlePoints, point);
    normal.Set(track.Normals[pointIndex]);
}

float ZCalculator::GetNearestMiddlePointZ(Array<Vector3d, TrackMaxMiddlePoints>& middlePoints, Vector3d& point)
{
    Vector3d v(middlePoints[0]);
    v.Sub(point);
    float minLength = v.GetLengthSquared();
    float z = v.Z;
    for (int i = 1; i < middlePoints.Count; i++)
    {
        v = middlePoints[i];
        v.Sub(point);
        float length = v.GetLengthSquared();
        if (length < minLength)
        {
            minLength = length;
            z = v.Z;
        }
    }

    return z;
}

int ZCalculator::GetNearestTrackPointIndex(Vector3d& point, Track& track)
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
