#include "lib/Array.h"
#include "core/ZCalculator.h"

void ZCalculator::CalculateZ(Ship& ship, Track& track)
{
    //CalculateForPoint(ship.CentralLine.Front, track);
    //CalculateForPoint(ship.CentralLine.Rear, track);
    CalculateForPoint(ship.Border.UpLeft, track);
    CalculateForPoint(ship.Border.UpRight, track);
    CalculateForPoint(ship.Border.DownLeft, track);
    CalculateForPoint(ship.Border.DownRight, track);
}

void ZCalculator::CalculateForPoint(Vector3d& point, Track& track)
{
    int pointIndex = GetNearestTrackPointIndex(point, track);
    Array<Vector3d, TrackMaxMiddlePoints>& middlePoints = track.MiddlePoints[pointIndex];
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
    point.Z = z;
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
