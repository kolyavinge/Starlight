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
            OutsidePoints[pointIndex + 1],
            Normals[pointIndex]);
    }

    VectorCalculator::GetNormalVector3d(
        InsidePoints[PointsCount - 1],
        OutsidePoints[PointsCount - 1],
        OutsidePoints[0],
        Normals[PointsCount - 1]);

    if (OutsidePoints[0].X < InsidePoints[0].X)
    {
        for (int pointIndex = 0; pointIndex < PointsCount; pointIndex++)
        {
            Normals[pointIndex].Mul(-1.0f);
        }
    }
}
