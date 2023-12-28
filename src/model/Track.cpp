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

int Track::GetNearestTrackPointIndex(TrackPoints& trackPoints, Vector3d& point)
{
    int result = 0;
    Vector3d v(trackPoints[0]);
    v.Sub(point);
    float minLength = v.GetLengthSquared();
    for (int i = 1; i < PointsCount; i++)
    {
        v = trackPoints[i];
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
