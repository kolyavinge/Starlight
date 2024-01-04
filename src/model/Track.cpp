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
    InitMiddlePoints();
    InitNormals();
    StraightDirection.Normalize();
    _startFinishLine.Set(OutsidePoints[StartFinishLineIndex]);
    _startFinishLine.Sub(InsidePoints[StartFinishLineIndex]);
}

int Track::GetTrackPointIndexFor(Vector3d& point, int startIndex)
{
    int result = startIndex;
    float minLength = GetMinSquaredLengthForTrackPoint(point, startIndex);
    for (int i = GetNextTrackPointIndex(startIndex); true; i = GetNextTrackPointIndex(i))
    {
        float length = GetMinSquaredLengthForTrackPoint(point, i);
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
        float length = GetMinSquaredLengthForTrackPoint(point, i);
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

bool Track::IsShipMovingInStraightDirection(Vector3d& shipStraightDirection)
{
    return VectorCalculator::IsSameDirection(_startFinishLine, shipStraightDirection, StraightDirection);
}

void Track::InitMiddlePoints()
{
    for (int pointIndex = 0; pointIndex < PointsCount; pointIndex++)
    {
        Vector3d v(OutsidePoints[pointIndex]);
        v.Sub(InsidePoints[pointIndex]);
        v.Div((float)TrackMaxMiddlePoints + 1.0f);

        MiddlePoints[pointIndex][0] = InsidePoints[pointIndex];
        MiddlePoints[pointIndex][0].Add(v);

        for (int i = 1; i < TrackMaxMiddlePoints; i++)
        {
            MiddlePoints[pointIndex][i] = MiddlePoints[pointIndex][i - 1];
            MiddlePoints[pointIndex][i].Add(v);
        }
    }
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

float Track::GetMinSquaredLengthForTrackPoint(Vector3d& point, int trackPointIndex)
{
    Array<Vector3d, TrackMaxMiddlePoints>& middlePoints = MiddlePoints[trackPointIndex];
    Vector3d v(middlePoints[0]);
    v.Sub(point);
    float minLengthSquared = v.GetLengthSquared();
    for (int i = 1; i < TrackMaxMiddlePoints; i++)
    {
        v = middlePoints[i];
        v.Sub(point);
        float length = v.GetLengthSquared();
        if (length < minLengthSquared)
        {
            minLengthSquared = length;
        }
    }

    return minLengthSquared;
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
