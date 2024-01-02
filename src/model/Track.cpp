#include <calc/VectorCalculator.h>
#include <model/Track.h>

Track::Track()
{
    PointsCount = 0;
    StartFinishLineIndex = 0;
}

void Track::Init()
{
    InternalInit();
    InitNormals();
}

int Track::GetNearestTrackPointIndex(TrackPoints& trackPoints, Vector3d& point, int startIndex)
{
    int result = startIndex;
    Vector3d v(trackPoints[startIndex]);
    v.Sub(point);
    float minLength = v.GetLengthSquared();
    for (int i = GetNextTrackPointIndex(startIndex); true; i = GetNextTrackPointIndex(i))
    {
        v = trackPoints[i];
        v.Sub(point);
        float length = v.GetLengthSquared();
        if (length < minLength)
        {
            minLength = length;
            result = i;
        }
        else
        {
            break;
        }
    }
    for (int i = GetPrevTrackPointIndex(startIndex); true; i = GetPrevTrackPointIndex(i))
    {
        v = trackPoints[i];
        v.Sub(point);
        float length = v.GetLengthSquared();
        if (length < minLength)
        {
            minLength = length;
            result = i;
        }
        else
        {
            break;
        }
    }

    return result;
}

void Track::InitNormals()
{
    for (int pointIndex = 0; pointIndex < PointsCount - 1; pointIndex++)
    {
        VectorCalculator::GetNormalVector3d(
            InsidePoints[pointIndex],
            OutsidePoints[pointIndex],
            InsidePoints[pointIndex + 1],
            Normals[pointIndex]);
    }

    VectorCalculator::GetNormalVector3d(
        InsidePoints[PointsCount - 1],
        OutsidePoints[PointsCount - 1],
        InsidePoints[0],
        Normals[PointsCount - 1]);

    if (OutsidePoints[0].X < InsidePoints[0].X)
    {
        for (int pointIndex = 0; pointIndex < PointsCount; pointIndex++)
        {
            Normals[pointIndex].Mul(-1.0f);
        }
    }
}

int Track::GetNextTrackPointIndex(int currentIndex)
{
    currentIndex++;
    if (currentIndex == PointsCount) currentIndex = 0;

    return currentIndex;
}

int Track::GetPrevTrackPointIndex(int currentIndex)
{
    currentIndex--;
    if (currentIndex == -1) currentIndex = PointsCount - 1;

    return currentIndex;
}
